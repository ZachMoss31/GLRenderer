
#include <GL/glut.h>
//#include <glew/glew.h>

#include <iostream>


//Window Data...
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

GLfloat vertices[] = {
	//Position Vectors	
	-0.9f, -0.5f, 0.0f,
	0.0f, -0.5f, 0.0f,
	-0.45f, 0.5f, 0.0f
};

//Written to just pull this out of the main file flow.
void DisplayGL() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	GLfloat Red = 0.0f, greenVal = 0.0f, Blue = 0.0f, Alpha = 1.0f;

	//Move to the animation tab?
	float elapsedTime = glutGet( GLUT_ELAPSED_TIME );
	greenVal = sin(elapsedTime / 2.0f + 0.5f);
	glClearColor(Red, greenVal, Blue, Alpha);

	// OPENGL DRAW CALLS HERE

	//glUseProgram( program );
	//glDrawArrays( GL_POINTS, 0, num_vertices );
	//MyShader.Use();
	//VAO1.Bind();
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	
	glutSwapBuffers();
}

void KeyBoardFunction(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		
		//glutLeaveMainLoop();
		std::cout << "Key ESC was pressed" << std::endl;
		break;
	}
}

void MouseFunction(int button, int state, int x, int y) {

}

void MouseMotionFunction(int x, int y) {

}

void IdleFunction() {
	//Handle Animation
	//Tell GLUT to redraw!

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat Red = 0.0f, greenVal = 0.0f, Blue = 0.0f, Alpha = 1.0f;

	float elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	float lastFrameElapsed = 0.0f;
	float deltaTime = (elapsedTime - lastFrameElapsed) / 1000.0f;

	greenVal = sin(deltaTime);
	if (greenVal < 0.0f)
		greenVal *= -1;

	glClearColor(Red, greenVal, Blue, Alpha);

	printf("\rGreenVal: %f\tDelta Time: %f", greenVal, deltaTime);
	glutPostRedisplay();
	lastFrameElapsed = elapsedTime;
	
}



int main(int argc, char** argv) {
	//-------------------------------------------------------- FreeGLUT -------
	//---------- Initialization ----------
	glutInit(&argc, argv);
	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	GLuint window = glutCreateWindow("My Glut Window");
	std::cout << "Using OpenGL Version " << glGetString(GL_VERSION) << std::endl; // 4.6
	glutDisplayFunc(DisplayGL);
	
	//---------- Keyboard ----------
	glutKeyboardFunc(KeyBoardFunction);
	//glutPassiveMotionFUnc(myMousePassive);

	//---------- Main Loop ----------
	glutIdleFunc(IdleFunction);
	glutMainLoop();
	

	/*VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();*/


	return 0;
}