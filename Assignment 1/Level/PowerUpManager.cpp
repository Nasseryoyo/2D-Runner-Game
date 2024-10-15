#include <Level/PowerUpManager.h>

PowerUpManager::PowerUpManager() {}

void PowerUpManager::update(float deltaTime) {
	for (auto& powerUp : powerUps) {
		powerUp.update(deltaTime);
	}
}

void PowerUpManager::render() {
	for (auto& powerUp : powerUps) {
		powerUp.render();
	}
}

void PowerUpManager::addPowerUp(float startX, float startY) {

	powerUps.emplace_back(startX, startY);
}

const std::vector<PowerUp>& PowerUpManager::getPowerUps() const {
	return powerUps;
}