#include "Game Objects/Obstacle.h"
#include <GL/glut.h>

extern int windowHeight;


Obstacle::Obstacle(float startX, float startY, bool reverseDirection) {

	x = startX;
	y = startY;
	width = 20.0f;
	height = 40.0f;
	speed = 100.0f;
	this->reverseDirection = reverseDirection;

}

void Obstacle::update(float deltaTime) {
	// Move the obstacle from right to left
	x -= speed * deltaTime;

}

void Obstacle::render() {

	if (reverseDirection) {
		// Draw the obstacle with the triangle facing downward and the quad above it
		glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
		glBegin(GL_QUADS);
		// Rectangle
		glVertex2f(x, y + (height / 2));
		glVertex2f(x + width, y + (height / 2));
		glVertex2f(x + width, y + height);
		glVertex2f(x, y + height);
		glEnd();

		glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
		glBegin(GL_TRIANGLES);
		glVertex2f(x, y + (height / 2));
		glVertex2f(x + width / 2, y);
		glVertex2f(x + width, y + height / 2);
		glEnd();
	}
	else {
		// Draw the obstacle with the triangle facing upward and the quad below it
		glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
		glBegin(GL_QUADS);
		// Rectangle
		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y + (height / 2));
		glVertex2f(x, y + (height / 2));
		glEnd();

		glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
		glBegin(GL_TRIANGLES);
		glVertex2f(x, y + (height / 2));
		glVertex2f(x + width / 2, y + (height));
		glVertex2f(x + width, y + (height / 2));
		glEnd();
	}

}

float Obstacle::getX() const {
	return x;
}

float Obstacle::getY() const {
	return y;
}

float Obstacle::getWidth() const {
	return width;
}

float Obstacle::getHeight() const {
	return height;
}



