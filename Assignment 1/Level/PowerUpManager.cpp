#include <Level/PowerUpManager.h>

PowerUpManager::PowerUpManager() {}

void PowerUpManager::update(float deltaTime) {
	for (auto& powerUp : powerUps) {
		powerUp.update(deltaTime);
	}

	// Remove collected coins
	powerUps.erase(
		std::remove_if(powerUps.begin(), powerUps.end(), [](PowerUp& power) {
			return power.isCollected();
			}),
		powerUps.end()
	);
}

void PowerUpManager::render() {
	for (auto& powerUp : powerUps) {
		powerUp.render();
	}
}

void PowerUpManager::addPowerUp(float startX, float startY) {

	powerUps.emplace_back(startX, startY);
}

std::vector<PowerUp>& PowerUpManager::getPowerUps() {
	return powerUps;
}