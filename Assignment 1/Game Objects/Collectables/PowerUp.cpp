#include "Game Objects/Collectibles/PowerUp.h"
#include <random>

#include <GL/glut.h>

extern int windowHeight;
extern int windowWidth;
extern float speedUp;

extern std::default_random_engine generator;
std::uniform_int_distribution<int> powerUpDistribution(1, 2);



PowerUp::PowerUp(float startX, float startY) {
	x = startX;
	y = startY;
	width = 40.0f;
	height = 40.0f;
	speed = 100.0f;
	dx = 0.0f;
	powerUpType = powerUpDistribution(generator);
	collected = false;

}

PowerUp::~PowerUp() {
}

void PowerUp::update(float deltaTime) {
	// Move the power-up from right to left
	x -= speed * deltaTime + deltaTime * speedUp;
}

void PowerUp::setCollected(bool flag) {
	collected = flag;
}

bool PowerUp::isCollected() {
	return collected;
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

			// Invincibility power-up with a shield in the middle
			float shieldWidth = width / 2;
			float shieldHeight = height / 2;
			float shieldX = x + (width - shieldWidth) / 2;
			float shieldY = y + (height - shieldHeight) / 2;

			// Draw shield using GL_POLYGON for the top part (rectangle)
			glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
			glBegin(GL_POLYGON);
			glVertex2f(shieldX, shieldY + shieldHeight / 2);
			glVertex2f(shieldX + shieldWidth, shieldY + shieldHeight / 2);
			glVertex2f(shieldX + shieldWidth, shieldY + shieldHeight);
			glVertex2f(shieldX, shieldY + shieldHeight);
			glEnd();

			// Draw shield using GL_TRIANGLES for the bottom part (triangle)
			glBegin(GL_TRIANGLES);
			glVertex2f(shieldX, shieldY + shieldHeight / 2);
			glVertex2f(shieldX + shieldWidth, shieldY + shieldHeight / 2);
			glVertex2f(shieldX + shieldWidth / 2, shieldY - shieldHeight / 4);
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

			// Jump boost power-up with an arrow in the middle
			float arrowWidth = width / 2;
			float arrowHeight = height / 2;
			float arrowX = x + (width - arrowWidth) / 2;
			float arrowY = y + (height - arrowHeight) / 3;

			// Draw arrow using GL_POLYGON for the shaft
			glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
			glBegin(GL_POLYGON);
			glVertex2f(arrowX + arrowWidth / 4, arrowY);
			glVertex2f(arrowX + 3 * arrowWidth / 4, arrowY);
			glVertex2f(arrowX + 3 * arrowWidth / 4, arrowY + arrowHeight);
			glVertex2f(arrowX + arrowWidth / 4, arrowY + arrowHeight);
			glEnd();

			// Draw arrow using GL_TRIANGLES for the head
			glBegin(GL_TRIANGLES);
			glVertex2f(arrowX, arrowY + arrowHeight);
			glVertex2f(arrowX + arrowWidth / 2, arrowY + 1.5 * arrowHeight);
			glVertex2f(arrowX + arrowWidth, arrowY + arrowHeight);
			glEnd();
		}
		// Add glint effect using GL_LINES
		glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
		glLineWidth(2.0f); // Set line width
		glBegin(GL_LINES);
		// Glint effect
		glVertex2f(x, y + height);
		glVertex2f(x + width, y);
		glEnd();
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

