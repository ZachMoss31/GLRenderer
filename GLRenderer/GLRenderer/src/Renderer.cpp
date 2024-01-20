#include <GL/freeglut.h>
#include <GL/glut.h>
//#include <glew/glew.h>

#include <iostream>


//Window Data...
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

GLfloat vertices[] = {
	//Position Vectors		//Color Vectors (r, g, b)
	-0.9f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,
	0.0f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,
	-0.45f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f
};

GLfloat flipTri[] = {
	0.0f, 0.5f, 0.0f,
	0.9f, 0.5f, 0.0f,
	0.45f, -0.5f, 0.0f
};

//Written to just pull this out of the main file flow.
static void RenderSceneCB() {
	static GLclampf c = 0.0f;
	glClearColor(c, c, c, c);
	c += 1.0f / 256.0f;
	if (c >= 1.0f) {
		c = 0.0f;
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	//-------------------------------------------------------- FreeGLUT -------
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
	glutInitWindowPosition(200, 100);
	GLuint window = glutCreateWindow("My Glut Window");
	GLclampf Red = 0.0f, Green = .7f, Blue = 0.0f, Alpha = .5f;
	glClearColor(Red, Green, Blue, Alpha);
	glutDisplayFunc(RenderSceneCB);
	glutMainLoop();

	//-------------------------------------------------------- SHADERS -------
	//Shader ourShader("src/shaders/3.3.shader.vs", "src/shaders/3.3.shader.fs");
	//Shader secondShader("src/shaders/3.3.shader.vs", "src/shaders/GreenGlow.fs");

	/*
	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	//Link attribut 1 is to add second set of vectors as colors in 'vertices'.
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();

	VAO VAO2;
	VAO2.Bind();
	VBO VBO2(flipTri, sizeof(flipTri));
	VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 0, (void*)0);
	VAO2.Unbind();
	VBO2.Unbind();
	float timeValue = 1.0f;
	float greenGlow = 1.0f;

	*/

	/*
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		//Background Color
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//First Triangle
		ourShader.Use();
		VAO1.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//Second Triangle
		secondShader.Use();
		timeValue = glfwGetTime();
		greenGlow = sin(timeValue) / 2.0f + 0.5f;
		glUniform1f(uniID, greenGlow);
		VAO2.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//How to make sure we refresh each frame
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	*/

	/*
	VAO1.Delete();
	VBO1.Delete();
	VAO2.Delete();
	VBO2.Delete();
	ourShader.Delete();
	secondShader.Delete();
	*/
	return 0;
}