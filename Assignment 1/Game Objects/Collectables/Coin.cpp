#include "Game Objects/Collectibles/Coin.h"
#include <GL/glut.h>

extern float speedUp;

Coin::Coin() {
	x = 0.0f;
	y = 0.0f;
	width = 40.0f;
	height = 40.0f;
	speed = 100.0f;
	collected = false;
}

Coin::Coin(float startX, float startY) {
	x = startX;
	y = startY;
	width = 40.0f;
	height = 40.0f;
	speed = 100.0f;
	collected = false;
}


Coin::~Coin() {
}

void Coin::update(float deltaTime) {
	// move the coin from right to left
	x -= speed * deltaTime + deltaTime * speedUp;
}

void Coin::render() {

	if (!collected) {
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y + height);
		glVertex2f(x, y + height);
		glEnd();
		// Draw inner rectangle at the center using GL_LINE_LOOP
		float innerWidth = width / 2;
		float innerHeight = height / 2;
		float innerX = x + (width - innerWidth) / 2;
		float innerY = y + (height - innerHeight) / 2;

		glBegin(GL_LINE_LOOP);
		glColor3f(1.0f, 0.8f, 0.0f);
		glVertex2f(innerX, innerY);
		glVertex2f(innerX + innerWidth, innerY);
		glVertex2f(innerX + innerWidth, innerY + innerHeight);
		glVertex2f(innerX, innerY + innerHeight);
		glEnd();

		// Draw glint rectangle as a small shadow using GL_POLYGON
		float glintWidth = width / 4;
		float glintHeight = height / 2; // Not the full height
		float glintX = x + width - glintWidth - 2.0f; // Slightly to the left
		float glintY = y + height / 4; // Centered vertically

		glBegin(GL_POLYGON);
		glColor3f(0.8f, 0.8f, 0.8f); // Slightly darker color for shadow effect
		glVertex2f(glintX, glintY);
		glVertex2f(glintX + glintWidth, glintY);
		glVertex2f(glintX + glintWidth, glintY + glintHeight);
		glVertex2f(glintX, glintY + glintHeight);
		glEnd();
	}
}


float Coin::getX() const {
	return x;
}

float Coin::getY() const {
	return y;
}

float Coin::getWidth() const {
	return width;
}

float Coin::getHeight() const {
	return height;
}

void Coin::setX(float x) {
	this->x = x;
}

void Coin::setY(float y) {
	this->y = y;
}

void Coin::setWidth(float width) {
	this->width = width;
}


void Coin::setHeight(float height) {
	this->height = height;
}

void Coin::setCollected(bool flag) {
	collected = flag;
}

bool Coin::isCollected() const {
	return collected;
}

