#include "Game Objects/Enviroment/Ground.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

#include <GL/glut.h>

extern int windowWidth;
extern int windowHeight;

Ground::Ground() {
	// Seed the random number generator
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	// Initialize 2 to 4 stones with random positions
	int numStones = 2 + std::rand() % 3; // Random number between 2 and 4
	for (int i = 0; i < numStones; ++i) {
		float stoneX = static_cast<float>(std::rand() % windowWidth);
		float stoneY = static_cast<float>(std::rand() % static_cast<int>(windowHeight * 0.25)) - windowHeight * 0.25;
		stones.emplace_back(stoneX, stoneY);
	}
}

void Ground::update(float deltaTime) {
	// Update stones
	for (auto& stone : stones) {
		stone.update(deltaTime);
	}
}

void Ground::draw() {
	float groundHeight = windowHeight * 0.25f;

	// Draw dirt
	glColor3f(0.6f, 0.4f, 0.2f); // Dirt color
	glBegin(GL_QUADS);
	glVertex2f(0, 0); // Top-left corner
	glVertex2f(windowWidth, 0); // Top-right corner
	glVertex2f(windowWidth, groundHeight); // Bottom-right corner
	glVertex2f(0, groundHeight); // Bottom-left corner
	glEnd();

	// Draw stones as points
	for (auto& stone : stones) {
		stone.render();
	}

	// Draw grass
	glColor3f(0.2f, 0.8f, 0.2f); // Grass color
	glBegin(GL_POLYGON);
	glVertex2f(0, groundHeight - 10); // Adjusted to be within the 25% height
	glVertex2f(windowWidth, groundHeight - 10); // Adjusted to be within the 25% height
	glVertex2f(windowWidth, groundHeight); // Adjusted to be within the 25% height
	glVertex2f(0, groundHeight); // Adjusted to be within the 25% height
	glEnd();
}
