#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
int main() {

	if (!glfwInit()) {
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(1280, 720,"Graphics Engine",nullptr,nullptr);
	if (!window) {
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(window);

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}