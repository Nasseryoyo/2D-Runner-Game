#include <Level/CollectibleManager.h>


CollectibleManager::CollectibleManager() {}

void CollectibleManager::update(float deltaTime) {
	for (auto& collectible : collectibles) {
		collectible.update(deltaTime);
	}
}

void CollectibleManager::render() {
	for (auto& collectible : collectibles) {
		collectible.render();
	}
}

void CollectibleManager::addCollectible(float startX, float startY) {
	collectibles.emplace_back(startX, startY);
}

const std::vector<Coin>& CollectibleManager::getCollectibles() const {
	return collectibles;
}