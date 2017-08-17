#include "ShardSpawner.h"

// The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = 1000;

void ShardSpawner::update(sf::Time& elapsed) {
	// Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;
	// If our timer has elapsed, reset it and spawn a meteor.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		// Spawn the meteor off the right side of the screen.
		// We're assuming the meteor isn't more than 100 pixels wide.
		float shardX = (float)(size.x + 100);

		// Spawn the meteor somewhere along the height of window, randomly.
		float shardY = (float)(rand() % size.y);

		// Create a meteor and add it to the scene
		ShardPtr shard = std::make_shared<Shard>(sf::Vector2f(shardX, shardY));
		GAME.getCurrentScene().addGameObject(shard);
	}
}
