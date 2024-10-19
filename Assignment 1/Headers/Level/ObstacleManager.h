#pragma once
#include <vector>
#include <Game Objects/Obstacle.h>

class ObstacleManager {
public:
	ObstacleManager();
	void update(float deltaTime);
	void render();
	void addObstacle(float startX, float startY, bool reverseDirection);
	std::vector<Obstacle>& getObstacles();
	void clearObstacles();

private:
	std::vector<Obstacle> obstacles;
};
