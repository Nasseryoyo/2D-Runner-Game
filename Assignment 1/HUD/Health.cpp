#include "HUD/Health.h"
#include <cmath>
#include <GL/glut.h>

extern int windowWidth;   // Referencing the global window width
extern int windowHeight;  // Referencing the global window height

Health::Health() : lives(5) {}

void Health::setLives(int lives) {
	this->lives = lives;
}

void Health::drawHeart(float x, float y, float size) {
	glBegin(GL_POLYGON);
	for (float angle = 0; angle < 2 * M_PI; angle += 0.1) {
		float a = size * (16 * pow(sin(angle), 3));
		float b = size * (13 * cos(angle) - 5 * cos(2 * angle) - 2 * cos(3 * angle) - cos(4 * angle));
		glVertex3f(x + a / 100.0f, y + b / 100.0f, 0.0);
	}
	glEnd();
}

void Health::drawHealth() {
	glColor3f(1.0f, 0.0f, 0.0f);  // Red color for hearts

	// Position hearts near the top-left corner
	float heartX = windowWidth * 0.05f;  // 5% from the left (close to the left edge)
	float heartY = windowHeight * 0.90f; // 85% from the bottom (below the score)

	// Draw hearts for each life
	for (int i = 0; i < lives; i++) {
		Health::drawHeart(heartX + (i * (windowWidth * 0.03f)), heartY, 100);  // Adjust heart spacing based on window width
	}
}

