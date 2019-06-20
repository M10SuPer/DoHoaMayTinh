// Lab5_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\glut.h"
#include <stdio.h> 
#include <stdlib.h> 
#include "shader.h" 

#ifdef _MSC_VER                         
#   pragma comment (lib, "opengl32.lib") 
#   pragma comment (lib, "glu32.lib") 
#   pragma comment (lib, "glew32.lib") 
#   pragma comment (lib, "freeglut.lib") 
#endif 

#define WND_WIDTH   640                     
#define WND_HEIGHT  360                     /* chi?u cao c?a s? */ 
#define WND_TITLE   "Lab05-3"               
#define VS_FILE     "vertex.glsl"           /* t?p tin m� ngu?n vertex shader */ 
#define FS_FILE     "fragment.glsl"         /* t?p tin m� ngu?n fragment shader */ 

typedef enum objectMode { CUBE, SPHERE, TORUS, TEAPOT } OBJECT_MODE;

/* tham s? cho fragment shader */
vec3 light = { 0.0f, 1.0f, 1.0f };       /* v? tr� ngu?n s�ng  */
vec3 ambient = { 0.1f, 0.1f, 0.1f };       /* m�u ambient */
vec3 diffuse = { 1.0f, 0.5f, 0.0f };       /* m�u diffuse */
vec3 specular = { 1.0f, 1.0f, 1.0f };       /* m�u specular */
float Ka = 0.1f;                     /* h? s? ambient */
float Kd = 1.0f;                     /* h? s? diffuse */
float Ks = 1.0f;                     /* h? s? specular */
float shininess = 32.0f;                    /* h? s? b�ng b? m?t */
vec3 camera = { 0.0f, 0.0f, 5.0f };       /* v? tr� camera */
float xAngle = 0.0f;                     /* g�c quay v?t th? */
float yAngle = 0.0f;
float zAngle = 0.0f;
int xMotion = 0;                            /* theo d�i di chuy?n chu?t */
int yMotion = 0;

GLSL_PROGRAM * prog = NULL;                 /* d?i tu?ng chuong tr�nh shader */
OBJECT_MODE obj = TEAPOT;                   /* v?t th? hi?n t?i dang hi?n th? */

void resize(int width, int height) {  /* thay d?i k�ch thu?c c?a s? */
	if (height == 0) height = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / height, 1.0f, 100.0f);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
}

void render() { /* d?ng h�nh */
				/* truy?n c�c tham s? v�o fragment shader */
	glslSetUniform3fv(prog, "lightPosition", light);
	glslSetUniform3fv(prog, "diffuseColor", diffuse);
	glslSetUniform1f(prog, "shininess", shininess);
	glslSetUniform1f(prog, "Ka", Ka);
	glslSetUniform1f(prog, "Kd", Kd);
	glslSetUniform1f(prog, "Ks", Ks);

	glClearColor(0.05f, 0.1f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(camera.x, 0.0f, camera.z,
		camera.x, 0.0f, camera.z - 1.0f,
		0.0f, 1.0f, 0.0f);
	/* v? ngu?n s�ng */
	glslDeactivate(prog);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(light.x, light.y, light.z);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(0.05, 4, 4);
	glPopMatrix();
	glslActivate(prog);

	/* v? khung c?nh */
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
	switch (obj) {
	case CUBE:      glutSolidCube(1.5f); break;
	case SPHERE:    glutSolidSphere(1.0f, 24, 24); break;
	case TORUS:     glutSolidTorus(0.5, 1.0f, 24, 24); break;
	case TEAPOT:    glutSolidTeapot(1.0f); break;
	}
	glutSwapBuffers();
}

void input(unsigned char key, int x, int y) { /* x? l� s? ki?n b�n ph�m */
	switch (key) {
	case 27: exit(0);
	case 'a':
	case 'A':   camera.x -= 0.1f; light.x += 0.1f; break;
	case 'd':
	case 'D':   camera.x += 0.1f; light.x -= 0.1f; break;
	case 'w':
	case 'W':   camera.z -= 0.1f; light.z += 0.1f; break;
	case 's':
	case 'S':   camera.z += 0.1f; light.z -= 0.1f; break;
	case 'X':   light.x += 0.1f; break;
	case 'Y':   light.y += 0.1f; break;
	case 'Z':   light.z += 0.1f; break;
	case 'x':   light.x -= 0.1f; break;
	case 'y':   light.y -= 0.1f; break;
	case 'z':   light.z -= 0.1f; break;
	case 'R':   if (diffuse.r < 1.0f)   diffuse.r += 0.01f; break;
	case 'G':   if (diffuse.g < 1.0f)   diffuse.g += 0.01f; break;
	case 'B':   if (diffuse.b < 1.0f)   diffuse.b += 0.01f; break;
	case 'r':   if (diffuse.r >= 0.0f)  diffuse.r -= 0.01f; break;
	case 'g':   if (diffuse.g >= 0.0f)  diffuse.g -= 0.01f; break;
	case 'b':   if (diffuse.b >= 0.0f)  diffuse.b -= 0.01f; break;
	case 'H':   if (shininess < 200.0f) shininess += 1.0f;  break;
	case 'h':   if (shininess > 6.0f)   shininess -= 1.0f;  break;
	case '[':   if (Kd >= 0.0f) Kd -= 0.05f; break;
	case ']':   if (Kd <  1.0f) Kd += 0.05f; break;
	case '{':   if (Ks >= 0.0f) Ks -= 0.05f; break;
	case '}':   if (Ks <  1.0f) Ks += 0.05f; break;
	case '<':   if (Ka >= 0.0f) Ka -= 0.05f; break;
	case '>':   if (Ka <  1.0f) Ka += 0.05f; break;
	case '1':   obj = CUBE;   break;
	case '2':   obj = SPHERE; break;
	case '3':   obj = TORUS;  break;
	case '4':   obj = TEAPOT; break;
	default:    break;
	}
}

void mouse(int button, int state, int x, int y) { /* x? l� s? ki?n chu?t */
	if (state == 0 && button == 0) { /* n�t tr�i du?c nh?n */
		xMotion = x;
		yMotion = y;
	}
}

void motion(int x, int y) { /* theo d�i chuy?n d?ng chu?t */
	if (xMotion) {
		if (xMotion > x) yAngle -= 2.0f;
		if (xMotion < x) yAngle += 2.0f;
		xMotion = x;
	}
	if (yMotion) {
		if (yMotion > y) xAngle -= 1.0f;
		if (yMotion < y) xAngle += 1.0f;
		yMotion = y;
	}
}

void idle() { /* x? l� khi kh�ng c� s? ki?n g� x?y ra */
	glutPostRedisplay();
}

GLboolean init(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(-1, -1);
	glutInitWindowSize(WND_WIDTH, WND_HEIGHT);
	glutCreateWindow(WND_TITLE);
	glutDisplayFunc(render);
	glutIdleFunc(idle);
	glutReshapeFunc(resize);
	glutKeyboardFunc(input);
	glutMotionFunc(motion);
	glutMouseFunc(mouse);

	glEnable(GL_DEPTH_TEST);
	if (GLEW_OK != glewInit()) return GL_FALSE;
	if (!(prog = glslCreate())) printf("No GLSL supported.\n");
	glslCompileFile(prog, VERTEX_SHADER, VS_FILE);
	glslCompileFile(prog, FRAGMENT_SHADER, FS_FILE);
	glslLink(prog);
	glslActivate(prog);
	glslSetUniform3fv(prog, "ambientColor", ambient);
	glslSetUniform3fv(prog, "specularColor", specular);

	return GL_TRUE;
}

void done() {
	glslDestroy(prog);
}

void run() {
	glutMainLoop();
}

int main(int argc, char ** argv) {
	init(argc, argv);
	run();
	return 0;
}