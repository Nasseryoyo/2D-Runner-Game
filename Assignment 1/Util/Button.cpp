// Button.cpp
#include "Utils/Button.h"
#include <GL/glut.h>

Button::Button(std::string text, float x, float y, float width, float height)
	: text(text), x(x), y(y), width(width), height(height) {}

void Button::draw() {
	// Draw button outline
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + width, y, 0.0f);
	glVertex3f(x + width, y - height, 0.0f);
	glVertex3f(x, y - height, 0.0f);
	glEnd();

	// Draw button inner part
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + width, y, 0.0f);
	glVertex3f(x + width, y - height, 0.0f);
	glVertex3f(x, y - height, 0.0f);
	glEnd();

	// Draw button text
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos3f(x + width / 4, y - height / 4, 0.0f);
	for (char c : text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
}

bool Button::isClicked(float mouseX, float mouseY) {
	return mouseX >= x && mouseX <= x + width &&
		mouseY <= y && mouseY >= y - height;
}


float Button::getX() const {
	return x;
}

float Button::getY() const {
	return y;
}

float Button::getWidth() const {
	return width;
}

float Button::getHeight() const {
	return height;
}
