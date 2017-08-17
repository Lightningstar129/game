#include "Laser.h"

const float SPEED = 1.2f;

Laser::Laser(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Art/laser.png"));
	sprite_.setPosition(pos);
	assignTag("laser");
	setCollisionCheckEnabled(true);
}
void Laser::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Laser::update(sf::Time& elapsed) {
	printf("Laser::update\n");
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x > GAME.getRenderWindow().getSize().x)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Laser::getCollisionRect()
{
	printf("here\n");
	return sprite_.getGlobalBounds();
}