#include "Game Objects/Collectibles/Coin.h"
#include <GL/glut.h>

Coin::Coin() {
	x = 0.0f;
	y = 0.0f;
	width = 20.0f;
	height = 20.0f;
	speed = 100.0f;
	collected = false;
}

Coin::Coin(float startX, float startY) {
	x = startX;
	y = startY;
	width = 20.0f;
	height = 20.0f;
	speed = 100.0f;
	collected = false;
}


Coin::~Coin() {
}

void Coin::update(float deltaTime) {
	// move the coin from right to left
	x -= speed * deltaTime;
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

