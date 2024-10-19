#include "Game Objects/Enviroment/Mountain.h"
#include <GL/glut.h>

extern int windowWidth;
extern int windowHeight;
extern float speedUp;

Mountain::Mountain() {
	x = 0.0f;  // Initial x position
	y = 0.0f;  // Initial y position
	width = 10.0f;  // Initial width
	height = 10.0f;  // Initial height
	speed = 0.0f;  // Initial speed
}

Mountain::Mountain(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	speed = 20.0f;  // Initial speed
}

Mountain::~Mountain() {
}

float Mountain::getX() {
	return x;
}

float Mountain::getWidth() {
	return width;
}

void Mountain::update(float deltaTime) {
	x -= speed * deltaTime + deltaTime * speedUp;
	if (x + width < 0) {
		x = windowWidth;
	}
}


void Mountain::render() {
	// Draw mountain base
	glColor3f(0.3f, 0.2f, 0.1f); // Mountain base color
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + (width / 2), y + height);
	glVertex2f(x + width, y);
	glEnd();

	// Draw mountain shading
	glColor3f(0.2f, 0.1f, 0.05f); // Darker shade for the left side
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + (width / 2), y + height);
	glVertex2f(x + (width / 2), y);
	glEnd();

	// Draw snow cap
	glColor3f(1.0f, 1.0f, 1.0f); // Snow cap color
	glBegin(GL_TRIANGLES);
	glVertex2f(x + (width / 2.7), y + (3 * height / 4));
	glVertex2f(x + (width / 2), y + height);
	glVertex2f(x + (3 * width / 4.75), y + (3 * height / 4));
	glEnd();

}
