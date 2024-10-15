#pragma once
#include <vector>
#include <Game Objects/Collectibles/PowerUp.h>

class PowerUpManager {
public:
	PowerUpManager();
	void update(float deltaTime);
	void render();
	void addPowerUp(float startX, float startY);
	const std::vector<PowerUp>& getPowerUps() const;
private:
	std::vector<PowerUp> powerUps;

};
