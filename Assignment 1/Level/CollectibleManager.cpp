#include <Level/CollectibleManager.h>


CollectibleManager::CollectibleManager() {}

void CollectibleManager::update(float deltaTime) {
	for (auto& collectible : collectibles) {
		collectible.update(deltaTime);
	}
	// Remove collected coins
	collectibles.erase(
		std::remove_if(collectibles.begin(), collectibles.end(), [](Coin& coin) {
			return coin.isCollected();
			}),
		collectibles.end()
	);
}

void CollectibleManager::render() {
	for (auto& collectible : collectibles) {
		collectible.render();
	}
}

void CollectibleManager::addCollectible(float startX, float startY) {
	collectibles.emplace_back(startX, startY);
}

std::vector<Coin>& CollectibleManager::getCollectibles() {
	return collectibles;
}