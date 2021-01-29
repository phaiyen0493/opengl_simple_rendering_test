//Name: Yen Pham
//Assignment 1
//CS 5320

#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <Windows.h>

using namespace std;

float f(float x, float y)
{
	double power_cof = 0 - (pow(x, 2) + pow(y, 2));
	return exp(power_cof);
}

float* n(float x, float y)
{
	float n[3];
	float fx = f(x, y);
	float denominator = sqrt(4*pow(x,2)*pow(fx, 2) + 4*pow(y,2)*pow(fx,2) + 1);
	n[0] = 0-((2*x*fx)/denominator);
	n[1] = 0 - ((2 * y * fx) / denominator);
	n[2] = 1/denominator;
	return n;
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float X_min, X_max;
	float Y_min, Y_max;
	int N_x, N_y;

	X_min = -1;
	X_max = 1;
	Y_min = -1;
	Y_max = 1;

	N_x = 31;
	N_y = 31;

	float dx = (X_max - X_min) / (N_x - 1);
	float dy = (Y_max - Y_min) / (N_y - 1);
	float sx = (X_max - X_min) / 2;
	float sy = (Y_max - Y_min) / 2;

	for (float x = X_min; x <= X_max - dx; x += dx)
	{
		for (float y = Y_min; y <= Y_max - dy; y += dy)
		{
			GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
			GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

			glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);

			glBegin(GL_LINE_LOOP);
			glVertex2f(x, y);
			glVertex2f(x, y + dy);
			glVertex2f(x + dx, y + dy);
			glVertex2f(x + dx, y);
			glEnd();
		}
	}
	
	for (float x = X_min; x <= X_max - dx; x += dx)
	{
		for (float y = Y_min; y <= Y_max - dy; y += dy)
		{
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);
			glShadeModel(GL_FLAT);

			GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
			GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
			GLfloat diffuse[] = { 0.0,1.0,0.0,1.0 };
			GLfloat specular[] = { 0.0,1.0,1.0,1.0 };

			glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);
			glLightfv(GL_LIGHT0, GL_AMBIENT, diffuse);
			glLightfv(GL_LIGHT0, GL_POSITION, specular);

			glBegin(GL_QUADS);
			glVertex3f(x, y, f(x, y));
			glVertex3f(x + dx, y, f(x + dx, y));
			glVertex3f(x + dx, y + dy, f(x + dx, y + dy));
			glVertex3f(x, y + dy, f(x, y + dy));
			glEnd();
		}
	}

	glutSwapBuffers();
}

void draw1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float X_min, X_max;
	float Y_min, Y_max;
	int N_x, N_y;

	X_min = -1;
	X_max = 1;
	Y_min = -1;
	Y_max = 1;

	N_x = 31;
	N_y = 31;

	float dx = (X_max - X_min) / (N_x - 1);
	float dy = (Y_max - Y_min) / (N_y - 1);
	float sx = (X_max - X_min) / 2;
	float sy = (Y_max - Y_min) / 2;

	for (float x = X_min; x <= X_max - dx; x += dx)
	{
		for (float y = Y_min; y <= Y_max - dy; y += dy)
		{
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);
			glShadeModel(GL_SMOOTH);

			GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
			GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
			GLfloat diffuse[] = { 0.0,1.0,0.0,1.0 };
			GLfloat specular[] = { 0.0,1.0,1.0,1.0 };

			glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);
			glLightfv(GL_LIGHT0, GL_AMBIENT, diffuse);
			glLightfv(GL_LIGHT0, GL_POSITION, specular);

			glBegin(GL_QUADS);
			glVertex3f(x, y, f(x, y));
			glVertex3f(x + dx, y, f(x + dx, y));
			glVertex3f(x + dx, y + dy, f(x + dx, y + dy));
			glVertex3f(x, y + dy, f(x, y + dy));
			glEnd();
		}
	}

	glutSwapBuffers();
}

void draw2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float X_min, X_max;
	float Y_min, Y_max;
	int N_x, N_y;

	X_min = -1;
	X_max = 1;
	Y_min = -1;
	Y_max = 1;

	N_x = 11;
	N_y = 11;

	float dx = (X_max - X_min) / (N_x - 1);
	float dy = (Y_max - Y_min) / (N_y - 1);
	float sx = (X_max - X_min) / 2;
	float sy = (Y_max - Y_min) / 2;

	for (float x = X_min; x <= X_max - dx; x += dx)
	{
		for (float y = Y_min; y <= Y_max - dy; y += dy)
		{
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);
			GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
			GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

			glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);

			glBegin(GL_LINE_LOOP);
			glVertex2f(x, y);
			glVertex2f(x, y + dy);
			glVertex2f(x + dx, y + dy);
			glVertex2f(x + dx, y);
			glEnd();
		}
	}

	for (float x = X_min; x <= X_max - dx; x += dx)
	{
		for (float y = Y_min; y <= Y_max - dy; y += dy)
		{
			GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
			GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

			glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);

			glBegin(GL_QUADS);
			glVertex3f(x, y, f(x, y));
			glVertex3f(x + dx, y, f(x + dx, y));
			glVertex3f(x + dx, y + dy, f(x + dx, y + dy));
			glVertex3f(x, y + dy, f(x, y + dy));
			glEnd();
		}
	}

	glutSwapBuffers();
}

void draw3()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float X_min, X_max;
	float Y_min, Y_max;
	int N_x, N_y;

	X_min = -1;
	X_max = 1;
	Y_min = -1;
	Y_max = 1;

	N_x = 11;
	N_y = 11;

	float dx = (X_max - X_min) / (N_x - 1);
	float dy = (Y_max - Y_min) / (N_y - 1);
	float sx = (X_max - X_min) / 2;
	float sy = (Y_max - Y_min) / 2;

	for (float x = X_min; x <= X_max - dx; x += dx)
	{
		for (float y = Y_min; y <= Y_max - dy; y += dy)
		{
			GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
			GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);
			glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);


			glBegin(GL_QUADS);
			glVertex3f(x, y, f(x, y));
			glVertex3f(x + dx, y, f(x + dx, y));
			glVertex3f(x + dx, y + dy, f(x + dx, y + dy));
			glVertex3f(x, y + dy, f(x, y + dy));
			glEnd();
		}
	}

	glutSwapBuffers();
}

void viewing(int W, int H)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5, 6, 3, 0, 0, 0, 0, 0, 5);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float aspect = (float) (W) / H;
	gluPerspective(25, aspect, 1, 10);

	glViewport(0, 0, W, H);

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(1200, 900);
	glutCreateWindow("30x30 elevation plot superimposed by domain plane");
	glutDisplayFunc(draw);
	glutReshapeFunc(viewing);

	glutCreateWindow("30x30 elevation plot without domain plane");
	glutPositionWindow(30, 40);
	glutDisplayFunc(draw1);
	glutReshapeFunc(viewing);

	glutCreateWindow("10x10 elevation plot superimposed by a domain plane");
	glutPositionWindow(30, 40);
	glutDisplayFunc(draw2);
	glutReshapeFunc(viewing);

	glutCreateWindow("10x10 elevation plot without a domain plane");
	glutPositionWindow(30, 40);
	glutDisplayFunc(draw3);
	glutReshapeFunc(viewing);

	glutMainLoop();

	return 0;
}