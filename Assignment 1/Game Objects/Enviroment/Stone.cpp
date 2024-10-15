#include "Game Objects/Enviroment/Stone.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include <Gl/glut.h>

extern int windowWidth;
extern int windowHeight;

Stone::Stone(float x, float y) : x(x), y(y) {}

void Stone::update(float deltaTime) {
	x -= 100.0f * deltaTime; // Adjust speed as needed
	if (x < -10) { // Ensure the stone is completely offscreen
		x = windowWidth + 10; // Reset the stone to the right with a margin
		y = static_cast<float>(std::rand() % static_cast<int>(windowHeight * 0.15)); // Ensure y is between 0 and 25% of window height
	}
}

void Stone::render() {
	glColor3f(0.5f, 0.3f, 0.2f); // Stone color
	glPointSize(20.0f); // Adjust point size as needed
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}