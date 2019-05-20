// Lab_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#define PI 3.1415
#define STEPS 40
#define MAX_STARS 300

const int screenWidth = 640;
const int screenHeight = 480;
const double r = 150;
const double pi = 3.14;

typedef struct star
{
	GLint x, y;
	GLint radius;
	GLint velocity;
	GLfloat intensity;
}STAR;
STAR sky[MAX_STARS];

struct GLdoublePoint
{
	GLdouble x;
	GLdouble y;
};

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*glClearColor(1.0, 1.0, 1.0, 1.0);*/
	/*glClearColor(1.0, 1.0, 1.0, 0.0);*/
	/*glShadeModel(GL_FLAT);*/
}

/*void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(10.0);

	glBegin(GL_POINTS);
		glVertex3f(200.0, 120.0, 0.0);
		glVertex3f(440.0, 120.0, 0.0);
		glVertex3f(440.0, 360.0, 0.0);
		glVertex3f(200.0, 360.0, 0.0);
	glEnd();
	
	glFlush();
}

void displayBai2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_TRIANGLES);
		glVertex2i(160, 80);
		glVertex2i(480, 80);
		glVertex2i(320, 400);
	glEnd();

	glFlush();
}*/

//void triangle()
//{
//	glBegin(GL_TRIANGLES);
//		glColor3f(1.0, 0.0, 0.0);
//		glVertex2i(50, 50);
//		glVertex2i(250, 50);
//		glVertex2i(150, 250);
//	glEnd();
//}
//
//void displayBai3()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	triangle();
//
//	glFlush();
//}
//--------------bai4----------
//void triangleBai4()
//{
//	glBegin(GL_TRIANGLES);
//	glColor3f(1.0, 0.0, 0.0);
//		glVertex2i(160, 80);
//		glColor3f(0.0, 1.0, 0.0);
//		glVertex2i(480, 80);
//		glColor3f(0.0, 0.0, 1.0);
//		glVertex2i(320, 400);
//	glEnd();
//}
//void displayBai4()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	triangleBai4();
//
//	glFlush();
//}

//----------------bai 5--------------
//void drawSquare(GLint x, GLint y, GLint a)
//{
//	glBegin(GL_POLYGON);
//		glVertex2i(x, y);
//		glVertex2i(x+a, y);
//		glVertex2i(x+a, y+a);
//		glVertex2i(x, y+a);
//	glEnd();
//}
//
//void displayBai5()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	GLint size = 200;
//	GLint x = (screenWidth - size) / 2;
//	GLint y = (screenHeight - size) / 2;
//	drawSquare(x, y, size);
//
//	glFlush();
//}



//-------------------bai 6------------------------

//void drawRectangle(GLint x, GLint y, GLint width,GLint height)
//{
//	glBegin(GL_POLYGON);
//		glVertex2i(x, y);
//		glVertex2i(x+width, y);
//		glVertex2i(x+width, y +height);
//		glVertex2i(x, y+height);
//	glEnd();
//}
//
//void displayBai6()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	GLint w=400,h=200;
//	GLint x = (screenWidth - w) / 2;
//	GLint y = (screenHeight - h) / 2;
//	drawRectangle(x, y, w,h);
//
//	glFlush();
//}


//------------------bai 7-----------------
//void drawRectangle(GLint x, GLint y, GLint width, GLint height)
//{
//	glBegin(GL_POLYGON);
//		glColor3f(1.0f, 0.0f ,1.0f);
//		glVertex2i(x, y);
//		glColor3f(0.0f, 1.0f, 1.0f);
//		glVertex2i(x + width, y);
//		glColor3f(1.0f,1.0f,0.0f);
//		glVertex2i(x + width, y + height);
//		glColor3f(1.0f,1.0f,1.0f);
//		glVertex2i(x, y + height);
//	glEnd();
//}
//
//void displayBai7()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	GLint w = 400, h = 200;
//	GLint x = (screenWidth - w) / 2;
//	GLint y = (screenHeight - h) / 2;
//	drawRectangle(x, y, w, h);
//
//	glFlush();
//}

//------------ bai 8 ---------------------------------

//void displayBai8()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.0, 0.0);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	glBegin(GL_TRIANGLES);
//	glVertex2i(50, 50);
//	glVertex2i(200, 50);
//	glVertex2i(100, 150);
//
//	glVertex2i(300, 150);
//	glVertex2i(450, 150);
//	glVertex2i(350, 250);
//	glEnd();
//
//	glFlush();
//}

//--------------bai 8 tiep tuc

//void displayBai8tt()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.0, 0.0);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	glBegin(GL_TRIANGLE_STRIP);
//	glVertex2i(50, 50);
//	glVertex2i(200, 50);
//	glVertex2i(100, 150);
//
//	glVertex2i(300, 150);
//	glVertex2i(450, 150);
//	glVertex2i(350, 250);
//	glEnd();
//
//	glFlush();
//}


//---------------------bai 9-----------------------------

//void displayBai9()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPointSize(5.0);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_POINTS);
//		GLdoublePoint v1, v2, v3, v4, v5, v0;
//		v0.x = screenWidth / 2;
//		v0.y = screenHeight / 2;
//		v1.x = v0.x;
//		v1.y = v0.y + r;
//		v2.x = v0.x + r*sin(2 * pi / 5);
//		v2.y = v0.y + r*cos(2 * pi / 5);
//		v3.x = v0.x + r*sin(pi / 5);
//		v3.y = v0.y - r*cos(pi / 5);
//		v4.x = v0.x - r*sin(pi / 5);
//		v4.y = v0.y - r*cos(pi / 5);
//		v5.x = v0.x - r*sin(2 * pi / 5);
//		v5.y = v0.y + r*cos(2 * pi / 5);
//
//		glVertex2d(v1.x, v1.y);
//		glVertex2d(v2.x, v2.y);
//		glVertex2d(v3.x, v3.y);
//		glVertex2d(v4.x, v4.y);
//		glVertex2d(v5.x, v5.y);
//	glEnd();
//	glFlush();
//}

//-------------------------bai 10--------------------------

void glCircle(GLint x,GLint y , GLint radius)
{
	GLfloat twicePi = (GLfloat) 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x, y);
	for (int i = 0; i <= STEPS; i++)
	{
		glVertex2i((GLint)(x + (radius *cos(i *twicePi / STEPS)) + 0.5), (GLint)(y + (radius *sin(i *twicePi / STEPS)) + 0.5));
	}
	glEnd();
}
//void displayBai10()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	
//	glCircle(320, 240, 150);
//
//	glFlush();
//}

//----------------------bai 11 ---------------------

//void displayBai11()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	GLfloat red = 1.0f;
//	GLfloat green = 1.0f;
//	GLfloat blue = 1.0f;
//	
//	for (int r = 200; r > 0; r -= 30)
//	{
//		glColor3f(red, green, blue);
//		glCircle(320, 240, r);
//		red -= 0.1f;
//		green -= 0.2f;
//		blue -= 0.3f;
//
//	}
//
//	glFlush();
//}


//---------------------------bai 12 --------------------





void skyInit()
{
	for (int i = 0; i < MAX_STARS; i++)
	{
		sky[i].x = rand() % screenWidth;
		sky[i].y = rand() % screenHeight;
		sky[i].radius = 1 + rand() % 3;
		sky[i].intensity = sky[i].radius / 3.0f;
		sky[i].velocity = sky[i].radius * 2 + rand() % 3;
	}
}
void skyDraw()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < MAX_STARS; i++)
	{
		glColor3f(sky[i].intensity, sky[i].intensity, sky[i].intensity);
		glCircle(sky[i].x, sky[i].y, sky[i].radius);
	}
}
void displayBai12()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	skyDraw();
	glPopMatrix();
	glutSwapBuffers();
}
void update()
{
	for (int i = 0; i < MAX_STARS; i++)
	{
		sky[i].x += sky[i].velocity;
		if (sky[i].x >= screenWidth)
		{
			sky[i].x = 0;
			sky[i].y = rand() % screenHeight;
			sky[i].radius = 1 + rand() % 3;
			sky[i].velocity = sky[i].radius / 3.0f;
			sky[i].velocity = sky[i].radius * 2 + rand() % 3;
		}
	}
	Sleep(50);
	glutPostRedisplay();
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	skyInit();
	glutDisplayFunc(displayBai12);
	glutReshapeFunc(reshape);
	glutIdleFunc(update);
	glutMainLoop();
    return 0;
}