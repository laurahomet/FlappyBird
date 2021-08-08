#include "../include/Obstacle.hpp"

Obstacle::Obstacle()
{
	setup();
}

void Obstacle::setup()
{
	if (!obst_top.loadFromFile("assets/pipe_top.png"))
	{
		throw "Could not load pipe_top.png";
	}

	if (!obst_bottom.loadFromFile("assets/pipe_bottom.png"))
	{
		throw "Could not load pipe_bottom.png";
	}

	int max = obst_top.getSize().y + (OBST_GAP / 2);
	int min = WIN_HEIGHT - max;
	int gap_pos = rand() % (max - min + 1) + min;

	top.setTexture(obst_top);
	top.setPosition(WIN_WIDTH, (double)gap_pos - (OBST_GAP / 2) - obst_top.getSize().y);
	top.setScale(sf::Vector2f(1.0f, 1.0f));

	bottom.setTexture(obst_bottom);
	bottom.setPosition(WIN_WIDTH, gap_pos + (OBST_GAP / 2));
	bottom.setScale(sf::Vector2f(1.0f, 1.0f));
}

void Obstacle::update()
{
	top.move(OBST_VEL, 0);
	bottom.move(OBST_VEL, 0);
}

bool Obstacle::section()
{
	int pos = top.getPosition().x;

	if (pos < next_section)
	{
		next_section = next_section - SECTION_GAP;
		return true;
	}

	return false;
}

bool Obstacle::disappear()
{
	return top.getPosition().x <= -OBST_WIDTH;
}

bool Obstacle::passed(int threshold)
{
	if (active and (top.getPosition().x + BIRD_RADIUS) < threshold)
	{
		active = false;
		return true;
	}
	return false;
}