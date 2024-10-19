#include "Game Objects/Enviroment/Enviroment.h"
#include <random>

extern int windowWidth;
extern int windowHeight;

extern std::default_random_engine generator;
std::uniform_real_distribution<float> cloudYDistribution(windowHeight * 0.7f, windowHeight * 0.9f);
std::uniform_real_distribution<float> mountainHeightDistribution(300.0f, 600.0f);

Enviroment::Enviroment() {
	// Create 5 clouds at different y positions
	for (int i = 0; i < 4; ++i) {
		clouds.emplace_back(windowWidth + windowWidth * (0.9f - i * 0.4f), cloudYDistribution(generator));
	}

	// Create 3 mountains with different heights
	for (int i = 0; i < 4; ++i) {
		mountains.emplace_back(windowWidth + windowWidth * (1.0f - i * 0.3f), 0, 600, mountainHeightDistribution(generator));
	}
}

Enviroment::~Enviroment() {
}

void Enviroment::update(float deltaTime) {
	// Update all clouds

	for (auto& cloud : clouds)
	{
		cloud.update(deltaTime);
	}

	// Update all mountains

	for (auto& mountain : mountains)
	{
		mountain.update(deltaTime);
	}
	ground.update(deltaTime);
}

void Enviroment::render() {
	// Render all mountains
	for (int i = 0; i < mountains.size(); ++i) {
		mountains[i].render();
	}
	// Render all clouds
	for (int i = 0; i < clouds.size(); ++i) {
		clouds[i].render();
	}

	ground.draw();
}

