#include "Orb.h"
#include "Explosion.h"
#include "GameScene.h"

const float SPEED = 0.25f;

Orb::Orb(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Art/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	setCollisionCheckEnabled(true);
}

void Orb::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Orb::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Orb::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void Orb::handleCollision(GameObject& otherGameObject)
{
	ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
	explosion->setOriginMode(OriginMode::TopMiddle);
	GAME.getCurrentScene().addGameObject(explosion);
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	scene.increaseScore();
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
	}
	makeDead();
}
