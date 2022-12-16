#include "libs.h"
#include <string.h>

const GLint WIDTH = 800, HEIGHT = 600;
GLuint VAO, VBO, shader;

// vertex shader
static const char* vShader = "						\n\
#version 330										\n\
													\n\
layout (location = 0) in vec3 pos;					\n\
													\n\
void main(){										\n\
	gl_Position = vec4(0.4 * pos.x, 0.4 * pos.y, pos.z, 1.0);	\n\
}";

static const char* fShader = "			\n\
#version 330							\n\
										\n\
out vec4 colour;						\n\
void main()								\n\
{										\n\
	colour = vec4(1.0, 0.0, 0.0, 1.0);  \n\
}";


void CreateTriangle() {
	GLfloat vertices[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f,0.0f,
		0.0f,1.0f,0.0f
	};
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

int main() {
	if (!glfwInit()) {
		printf("Error Initialising GLFW");
		glfwTerminate();
		return 1;
	}

	

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); only for mac



	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGlProject_Tutorial", NULL,NULL);
	if (!window) {
		printf("Error createing GLFW window");
		glfwTerminate();
		return 1;
	}

	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		printf("Error: %s", glewGetErrorString(error));
		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}
	glViewport(0, 0, bufferWidth, bufferHeight);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.1f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	return 0;
} 