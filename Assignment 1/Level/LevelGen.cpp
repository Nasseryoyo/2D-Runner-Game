#include "Level/LevelGen.h"

extern float groundLevel;
extern std::default_random_engine generator;

LevelGen::LevelGen() {
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

void LevelGen::resetLevel() {
	timeSinceLastObstacle = 0.0f;
	timeSinceLastCollectible = 0.0f;
	timeSinceLastPowerUp = 0.0f;
	obstacleSpawnRate = 2.0f;
	collectibleSpawnRate = 5.0f;
	powerUpSpawnRate = 10.0f;

	obstacleManager.clearObstacles();
	collectibleManager.clearCollectibles();
	powerUpManager.clearPowerUps();

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
		float obstacleY = (direction) ? groundLevel + groundLevel * 0.30f : groundLevel;

		obstacleManager.addObstacle(windowWidth, obstacleY, direction);
		timeSinceLastObstacle = 0.0f;

		// Spawn a coin or power-up in the path of the player
		if (timeSinceLastCollectible >= collectibleSpawnRate) {
			if (direction)
				collectibleManager.addCollectible(windowWidth + 10.0f, groundLevel + groundLevel * 0.05f);
			else
				collectibleManager.addCollectible(windowWidth + 10.0f, obstacleY + obstacleY / 2);
			timeSinceLastCollectible = 0.0f;
		}
		else if (timeSinceLastPowerUp >= powerUpSpawnRate) {
			if (direction)
				powerUpManager.addPowerUp(windowWidth + 10.0f, groundLevel + groundLevel * 0.05f);
			else
				powerUpManager.addPowerUp(windowWidth + 10.0f, obstacleY + obstacleY / 2);
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
