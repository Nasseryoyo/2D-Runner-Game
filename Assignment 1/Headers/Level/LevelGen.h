#pragma once
#include <vector>
#include <random>
#include "Level/ObstacleManager.h"
#include "Level/CollectibleManager.h"
#include "Level/PowerUpManager.h"


extern int windowHeight;
extern int windowWidth;

class LevelGen
{
public:
	LevelGen();
	void generateLevel();
	void update(float deltaTime);
	void render();
	void resetLevel();
	ObstacleManager& getObstacleManager();
	CollectibleManager& getCollectibleManager();
	PowerUpManager& getPowerUpManager();


private:
	ObstacleManager obstacleManager;
	CollectibleManager collectibleManager;
	PowerUpManager powerUpManager;
	float timeSinceLastObstacle;
	float timeSinceLastCollectible;
	float timeSinceLastPowerUp;
	float obstacleSpawnRate;
	float collectibleSpawnRate;
	float powerUpSpawnRate;
};


