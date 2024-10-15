#include "Level/LevelGen.h"

extern float groundLevel;

LevelGen::LevelGen() {
	generator = std::default_random_engine(std::random_device()());
	timeSinceLastObstacle = 0.0f;
	timeSinceLastCollectible = 0.0f;
	timeSinceLastPowerUp = 0.0f;
	obstacleSpawnRate = 2.0f;
	collectibleSpawnRate = 5.0f;
	powerUpSpawnRate = 10.0f;
}

void LevelGen::generateLevel() {
	timeSinceLastObstacle = 0.0f;
	timeSinceLastCollectible = 0.0f;
	timeSinceLastPowerUp = 0.0f;
	obstacleSpawnRate = 2.0f;
	collectibleSpawnRate = 5.0f;
	powerUpSpawnRate = 10.0f;
}

void LevelGen::update(float deltaTime) {
	timeSinceLastObstacle += deltaTime;
	timeSinceLastCollectible += deltaTime;
	timeSinceLastPowerUp += deltaTime;

	if (timeSinceLastObstacle >= obstacleSpawnRate) {
		// Determine the direction with a 50% chance
		std::uniform_int_distribution<int> distribution(0, 1);
		bool direction = distribution(generator) == 1;

		// Determine the y position of the obstacle
		float obstacleY = (direction) ? groundLevel + groundLevel * 0.1 : groundLevel;

		obstacleManager.addObstacle(windowWidth, obstacleY, direction);
		timeSinceLastObstacle = 0.0f;

		// Spawn a coin or power-up in the path of the player
		if (timeSinceLastCollectible >= collectibleSpawnRate) {
			if (direction)
				collectibleManager.addCollectible(windowWidth, obstacleY - obstacleY / 8);
			else
				collectibleManager.addCollectible(windowWidth, obstacleY + obstacleY / 2);
			timeSinceLastCollectible = 0.0f;
		}
		else if (timeSinceLastPowerUp >= powerUpSpawnRate) {
			if (direction)
				powerUpManager.addPowerUp(windowWidth, obstacleY - obstacleY / 8);
			else
				powerUpManager.addPowerUp(windowWidth, obstacleY + obstacleY / 2);
			timeSinceLastPowerUp = 0.0f;
		}
	}

	obstacleManager.update(deltaTime);
	collectibleManager.update(deltaTime);
	powerUpManager.update(deltaTime);
}

void LevelGen::render() {
	obstacleManager.render();
	collectibleManager.render();
	powerUpManager.render();
}

ObstacleManager& LevelGen::getObstacleManager() {
	return obstacleManager;
}

CollectibleManager& LevelGen::getCollectibleManager() {
	return collectibleManager;
}

PowerUpManager& LevelGen::getPowerUpManager() {
	return powerUpManager;
}
