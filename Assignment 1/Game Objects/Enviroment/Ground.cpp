#include "Game Objects/Enviroment/Ground.h"
#include <random> // For random number generation

#include <GL/glut.h>

extern int windowWidth;
extern int windowHeight;
extern std::default_random_engine generator;

Ground::Ground() {
	// Seed the random number generator
	std::uniform_real_distribution<float> dis(windowHeight * 0.05f, windowHeight * 0.1f);

	// Generate stones
	for (int i = 0; i < 5; i++) {
		stones.emplace_back(windowWidth + windowWidth * (0.9f - i * 0.4f), dis(generator));
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
	// Draw grass blades as triangles
	glColor3f(0.0f, 0.6f, 0.0f); // Darker green for grass blades
	for (int i = 0; i < windowWidth; i += 20) {
		glBegin(GL_TRIANGLES);
		glVertex2f(i, groundHeight - 10);
		glVertex2f(i + 10, groundHeight - 30);
		glVertex2f(i + 20, groundHeight - 10);
		glEnd();
	}
}
