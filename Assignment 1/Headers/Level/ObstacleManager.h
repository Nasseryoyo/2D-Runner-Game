#pragma once
#include <vector>
#include <Game Objects/Obstacle.h>

class ObstacleManager {
public:
	ObstacleManager();
	void update(float deltaTime);
	void render();
	void addObstacle(float startX, float startY, bool reverseDirection);
	const std::vector<Obstacle>& getObstacles() const;

private:
	std::vector<Obstacle> obstacles;
};
