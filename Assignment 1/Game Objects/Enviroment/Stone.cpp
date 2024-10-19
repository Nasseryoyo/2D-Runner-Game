#include "Game Objects/Enviroment/Stone.h"
#include <random> // For random number generation
#include <Gl/glut.h>

extern int windowWidth;
extern int windowHeight;
extern float speedUp;
extern std::default_random_engine generator;

std::uniform_real_distribution<float> dis(windowHeight * 0.05f, windowHeight * 0.1f);

Stone::Stone(float x, float y) : x(x), y(y) {}

void Stone::update(float deltaTime) {
	x -= 100.0f * deltaTime + deltaTime * speedUp;
	if (x < -10) { // Ensure the stone is completely offscreen
		x = windowWidth + 10;
		y = dis(generator);
	}
}

void Stone::render() {
	glColor3f(0.5f, 0.3f, 0.2f); // Stone color
	glPointSize(20.0f); // Adjust point size as needed
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}