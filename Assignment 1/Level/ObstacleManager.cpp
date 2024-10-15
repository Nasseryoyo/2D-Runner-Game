#include <Level/ObstacleManager.h>

ObstacleManager::ObstacleManager() {}

void ObstacleManager::update(float deltaTime) {
	for (auto& obstacle : obstacles) {
		obstacle.update(deltaTime);
	}
}

void ObstacleManager::render() {
	for (auto& obstacle : obstacles) {
		obstacle.render();
	}
}

void ObstacleManager::addObstacle(float startX, float startY, bool reverseDirection) {
	obstacles.emplace_back(startX, startY, reverseDirection);
}

const std::vector<Obstacle>& ObstacleManager::getObstacles() const {
	return obstacles;
}