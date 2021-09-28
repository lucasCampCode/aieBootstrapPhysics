#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include <iostream>
int main() {

	if (glfwInit() == GLFW_FALSE) {
		return -1;
	}
	//create glfw window
	GLFWwindow* window = glfwCreateWindow(1280, 720,"Graphics Engine",nullptr,nullptr);
	//if window wasm't sucefully created end application
	if (!window) {
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	//load openGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
	
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	//print openGL version to console
	printf("OpenGL version: %i.%i\n", ogl_GetMajorVersion(), ogl_GetMinorVersion());

	while (!glfwWindowShouldClose(window) 
		&& glfwGetKey(window,GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	//end application
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}