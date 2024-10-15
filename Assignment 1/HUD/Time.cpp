#include "HUD/Time.h"
#include <cstdio>
#include <GL/glut.h>

extern int windowWidth;   // Referencing the global window width
extern int windowHeight;  // Referencing the global window height

Time::Time() : gameTime(60.0f) {}  // Start with 60 seconds

void Time::updateTime(float deltaTime) {
	if (gameTime > 0) {
		gameTime -= deltaTime;
	}
	else {
		gameTime = 0;  // Prevent negative time
	}
}

void Time::drawTime() {
	glColor3f(1.0f, 1.0f, 1.0f);  // White color for time

	// Position the time display near the top-right corner
	float timeX = windowWidth * 0.9f;  // 95% from the left (close to the right edge)
	float timeY = windowHeight * 0.9f;  // 90% from the bottom (near the top edge)

	glRasterPos3f(timeX, timeY, 0.0f);

	char timeStr[20];
	sprintf_s(timeStr, "Time: %.1f", gameTime);
	for (char* c = timeStr; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

float Time::getTime() {
	return gameTime;
}
