#include "Game Objects/Enviroment/Cloud.h"
#include <cmath>
#include <GL/glut.h>

extern int windowWidth;
extern int windowHeight;

Cloud::Cloud() {
	x = 0.0f;  // Initial x position
	y = 0.0f;  // Initial y position
	speed = 100.0f;  // Initial speed
}

Cloud::Cloud(float x, float y) {
	this->x = x;
	this->y = y;
	speed = 100.0f;  // Initial speed
}

Cloud::~Cloud() {
}

void Cloud::update(float deltaTime) {
	x -= speed * deltaTime;
	if (x < -25.0f) x = windowWidth + 20.0f; // Reset cloud position to the right edge
}

static void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
	glBegin(GL_POLYGON);
	glVertex2f(cx, cy);
	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.1416 / 180;
		float x = rx * cos(angle);
		float y = ry * sin(angle);
		glVertex2f((x + cx), (y + cy));
	}
	glEnd();
}

void Cloud::render() {
	glColor3ub(255, 255, 255);

	circle(20, 30, x, y);

	circle(15, 20, x - 15, y);

	circle(15, 20, x + 15, y);
}




