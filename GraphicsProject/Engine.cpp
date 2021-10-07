#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "glm/ext.hpp"
#include "Engine.h"
#include <iostream>
Engine::Engine() : Engine(1280,720,"window")
{
	
}

Engine::Engine(int width, int height, const char* title)
{
	m_shader = new aie::ShaderProgram();
	m_scene = new Scene(width, height);
	m_width = width;
	m_height = height;
	m_title = title;
	m_fps = 0;
}


Engine::~Engine()
{
	delete m_scene;
	delete m_shader;
}

int Engine::run()
{
	int exitCode = 0; 
	exitCode = start();
	if (exitCode)
		return exitCode;
	double previousTime = 0.0f;
	double currentTime = 0.0f;
	double deltaTime = 0.0f;
	unsigned int frames = 0;
	double fpsInterval = 0.0f;


	while (getGameOver()) {
		// update delta time
		currentTime = glfwGetTime();
		deltaTime = currentTime - previousTime;
		if (deltaTime > 0.1f)
			deltaTime = 0.1f;

		previousTime = currentTime;

		// update fps every second
		frames++;
		fpsInterval += deltaTime;
		if (fpsInterval >= 1.0f) {
			m_fps = frames;
			frames = 0;
			fpsInterval -= 1.0f;
		}

		exitCode = update(deltaTime);
		if (exitCode)
			return exitCode;
		exitCode = draw(m_shader);
		if (exitCode)
			return exitCode;
	}

	if (exitCode = end() != 0)
		return exitCode;

	return 0;
}

int Engine::start()
{
	if (glfwInit() == GLFW_FALSE) return -1;

	//create glfw window
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	//if window wasm't sucefully created end application
	if (!m_window) {
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(m_window);

	//load openGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}

	//print openGL version to console
	printf("OpenGL version: %i.%i\n", ogl_GetMajorVersion(), ogl_GetMinorVersion());

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	//initialize the shader
	m_shader->loadShader(
		aie::eShaderStage::VERTEX,
		"simpleVert.shader"
	);
	m_shader->loadShader(
		aie::eShaderStage::FRAGMENT,
		"simpleFrag.shader"
	);
	if (!m_shader->link()) {
		printf("Shader Error: %s\n", m_shader->getLastError());
		return -10;
	}

	m_scene->setWindow(m_window);
	m_scene->start();

	return 0;
}

int Engine::update(double deltaTime)
{
	if (!m_window) return -4;

	glfwPollEvents();

	m_scene->update(deltaTime);

	return 0;
}

int Engine::draw(aie::ShaderProgram* shader)
{
	if (!m_window) return -5;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->bind();

	shader->bindUniform("projectionViewMatrix", m_scene->getProjectionView());

	m_scene->draw(shader);

	glfwSwapBuffers(m_window);

	return 0;
}

int Engine::end()
{
	if (!m_window) return -6;

	m_scene->end();

	//end application
	glfwDestroyWindow(m_window);
	glfwTerminate();

	return 0;
}

bool Engine::getGameOver()
{
	if (!m_window)
		return true;

	bool gameOver = !glfwWindowShouldClose(m_window);
	gameOver = gameOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return gameOver;
}
