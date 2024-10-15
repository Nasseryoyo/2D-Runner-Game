#include "Game Objects/Enviroment/Mountain.h"
#include <GL/glut.h>

extern int windowWidth;
extern int windowHeight;

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

void Mountain::update(float deltaTime) {
	x -= speed * deltaTime;
	if (x + width < -1) x = windowWidth; // Reset mountain position
}


void Mountain::render() {
	// Draw mountain
	glColor3f(0.3f, 0.2f, 0.1f); // Mountain color
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + (width / 2), y + height);
	glVertex2f(x + width, y);
	glEnd();

}
