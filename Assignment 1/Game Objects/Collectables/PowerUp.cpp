#include "Game Objects/Collectibles/PowerUp.h"
#include <random>

#include <GL/glut.h>

extern int windowHeight;
extern int windowWidth;

std::default_random_engine generator = std::default_random_engine(std::random_device()());
std::uniform_int_distribution<int> powerUpDistribution(1, 2);



PowerUp::PowerUp(float startX, float startY) {
	x = startX;
	y = startY;
	width = 20.0f;
	height = 20.0f;
	speed = 100.0f;
	dx = 0.0f;
	powerUpType = powerUpDistribution(generator);
	collected = false;

}

PowerUp::~PowerUp() {
}

void PowerUp::update(float deltaTime) {
	// Move the power-up from right to left
	x -= speed * deltaTime;
}

void PowerUp::setCollected(bool flag) {
	collected = flag;
}

void PowerUp::render() {

	if (!collected) {

		// Draw the power-up using a rectangle
		if (powerUpType == 1) {
			glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
			glBegin(GL_QUADS);
			// Rectangle
			glVertex2f(x, y);
			glVertex2f(x + width, y);
			glVertex2f(x + width, y + height);
			glVertex2f(x, y + height);
			glEnd();
		}
		else {
			glColor3f(0.0f, 1.0f, 0.0f); // Set color to blue
			glBegin(GL_QUADS);
			// Rectangle
			glVertex2f(x, y);
			glVertex2f(x + width, y);
			glVertex2f(x + width, y + height);
			glVertex2f(x, y + height);
			glEnd();
		}
	}
}

float PowerUp::getX() const {
	return x;
}

float PowerUp::getY() const {
	return y;
}

float PowerUp::getWidth() const {
	return width;
}

float PowerUp::getHeight() const {
	return height;
}

int PowerUp::getPowerUpType() const {
	return powerUpType;
}

void PowerUp::setPowerUpType(int type) {
	powerUpType = type;
}

void PowerUp::setX(float x) {
	this->x = x;
}

void PowerUp::setY(float y) {
	this->y = y;
}

void PowerUp::setWidth(float width) {
	this->width = width;
}

void PowerUp::setHeight(float height) {
	this->height = height;
}

PowerUp::PowerUp() {

	x = 0;
	y = 0;
	width = 0;
	height = 0;
	dx = 0;
	speed = 0;
	powerUpType = 0;
}

