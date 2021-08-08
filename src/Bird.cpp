#include "../include/Bird.hpp"

Bird::Bird()
{
	setup();
	acceleration = 0.0;
	velocity = 0.0;
	start_fall = 0;
}

void Bird::setup()
{
	if (!bird_fly.loadFromFile("assets/bird_fly.png"))
	{
		throw "Could not load bird_fly.png";
	}

	if (!bird_fall.loadFromFile("assets/bird_fall.png"))
	{
		throw "Could not load bird_fall.png";
	}

	body.setTexture(bird_fall);
	body.setPosition(WIN_WIDTH / 4, WIN_HEIGHT / 2);
	body.setScale(sf::Vector2f(BIRD_SCALE, BIRD_SCALE));
}

void Bird::fly()
{
	acceleration = ACC_FLY;
	start_fall = body.getPosition().y - FLY_MAX;
}

void Bird::fall()
{
	acceleration = ACC_FALL;
}

void Bird::update()
{
	velocity += acceleration;

	if (velocity > VEL_MAX)
		velocity = VEL_MAX;
	if (velocity < VEL_MIN)
		velocity = VEL_MIN;

	body.move(0, velocity);

	if (body.getPosition().y < start_fall)
	{
		fall();
	}
}