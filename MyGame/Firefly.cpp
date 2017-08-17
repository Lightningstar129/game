#include "Firefly.h"

#include <memory>


const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

Firefly::Firefly()
{
	sprite_.setTexture(GAME.getTexture("Art/half_firefly.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
	assignTag("firefly");
	setCollisionCheckEnabled(true);
}

void Firefly::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Firefly::update(sf::Time& elapsed) 
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))y -= SPEED*msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))y += SPEED*msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))x -= SPEED*msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))x += SPEED*msElapsed;

	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}
}

sf::FloatRect Firefly::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}