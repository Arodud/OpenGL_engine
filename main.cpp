#include <iostream>
#include <glew.h>
#include <freeglut.h>
#include "math.hpp"

GLuint VBO;

static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}


static void CreateVertexBuffer() {
	Vector3f Vertices[1];
	Vertices[0] = Vector3f( 0.0f, 0.0f, 0.0f );

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

}

int main(int argc, char** argv) {

	std::cout << "start" << '\n';
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

	const int width = 1920, heigth = 1080;
	glutInitWindowSize(width, heigth);

	int x = 200, y = 100;
	glutInitWindowPosition(x, y);

	int win = glutCreateWindow("GLUT created window");
	std::cout << "window id is " << win << '\n';

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Error: GLEW %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Started GLEW %s\n", glewGetString(GLEW_VERSION));

	GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);

	CreateVertexBuffer();
	
	glutDisplayFunc(RenderSceneCB);

	glutMainLoop();

}