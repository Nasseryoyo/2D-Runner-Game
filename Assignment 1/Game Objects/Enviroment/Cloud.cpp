#include "Game Objects/Enviroment/Cloud.h"
#include <cmath>
#include <random>
#include <GL/glut.h>

extern int windowWidth;
extern int windowHeight;

extern float speedUp;

extern std::default_random_engine generator;
extern std::uniform_real_distribution<float> cloudYDistribution;


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

float Cloud::getX() {
	return x;
}

float Cloud::getWidth() {
	return 40;
}

void Cloud::update(float deltaTime) {
	x -= speed * deltaTime + deltaTime * speedUp;
	if (x + getWidth() < 0) {
		x = windowWidth;
		y = cloudYDistribution(generator);
	}
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
	glColor3ub(255, 255, 255); // Set color to white

	// Draw main cloud body using circles
	circle(20, 30, x, y);
	circle(15, 20, x - 15, y);
	circle(15, 20, x + 15, y);

	// Add detail using different primitives

	// Draw a quad for additional cloud detail
	glBegin(GL_QUADS);
	glVertex2f(x - 10, y + 10);
	glVertex2f(x + 10, y + 10);
	glVertex2f(x + 10, y + 20);
	glVertex2f(x - 10, y + 20);
	glEnd();

	// Draw a triangle for additional cloud detail
	glBegin(GL_TRIANGLES);
	glVertex2f(x - 20, y - 10);
	glVertex2f(x - 10, y - 20);
	glVertex2f(x - 30, y - 20);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x - 20, y + 10);
	glVertex2f(x - 10, y + 20);
	glVertex2f(x + 20, y + 10);
	glVertex2f(x + 10, y + 20);
	glEnd();

	// Draw another circle for additional cloud detail
	circle(10, 15, x + 25, y + 10);
}




