#include "HUD/Score.h"
#include <stdio.h>
#include <GL/glut.h>

extern int windowWidth;   // Referencing the global window width
extern int windowHeight;  // Referencing the global window height

Score::Score() : score(0) {}

void Score::drawScore() {
	glColor3f(1.0f, 1.0f, 1.0f);  // White color for score

	// Position score near the top-left corner
	float scoreX = windowWidth * 0.05f;  // 5% from the left (close to the left edge)
	float scoreY = windowHeight * 0.95f;  // 90% from the bottom (near the top edge)

	glRasterPos3f(scoreX, scoreY, 0.0f);

	char scoreStr[20];
	sprintf_s(scoreStr, "Score: %d", score);
	for (char* c = scoreStr; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

int Score::getScore() {
	return score;
}

void Score::setScore(int Score) {
	score = Score;
}