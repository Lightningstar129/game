#include "Orb.h"
#include "Explosion.h"
#include "GameScene.h"

//const float SPEED = 0.25f;

Orb::Orb(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Art/half_darkness.png"));
	sprite_.setPosition(pos);
	assignTag("orb");
	setCollisionCheckEnabled(true);
	// rand			multiplier	SPEED
	// 0			0			lowest
	// RAND_MAX/4	1/4			quarter speed
	// RAND_MAX/2	1/2			half speed
	// RAND_MAX     1			full speed
	//SPEED = (float)rand()    RAND_MAX
	float percentage = (1/RAND_MAX)*rand();
	// pct	SPEED
	// 0    .01
	// .5   .13
	// 1    .25
	SPEED = ((0.24/1)*percentage) + 0.01;
}

void Orb::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Orb::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	if (pos.y < sprite_.getGlobalBounds().top * -1)
	{
		i = 1;
	}
	if (i == 1)
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y + SPEED * msElapsed));
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y - SPEED * msElapsed));
	}
	sf::Vector2u size = GAME.getRenderWindow().getSize();
	if (pos.y > size.y)
	{
		i = 0;
	}
}

sf::FloatRect Orb::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void Orb::handleCollision(GameObject& otherGameObject)
{
	/*ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
	explosion->setOriginMode(OriginMode::TopMiddle);
	GAME.getCurrentScene().addGameObject(explosion);*/
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	
	if (otherGameObject.hasTag("firefly"))
	{
		scene.decreaseLives();
		makeDead();
	}
}
