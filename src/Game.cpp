#include "../include/Game.hpp"

Game::Game(const char* title)
{
	setup(title);
	bird.fall();
}

Game::~Game()
{
	std::cout << "********************************* " << std::endl;
	std::cout << " Well played! Your score is... " << score << std::endl;
	std::cout << "********************************* " << std::endl;
}

void Game::setup(const char* title)
{

	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), title);

	if (!background_img.loadFromFile("assets/background.png"))
	{
		throw "Could not load background.png";
	}
	background.setTexture(background_img);
	background.setScale(sf::Vector2f(WIN_SCALE_X, WIN_SCALE_Y));
}

void Game::mainloop()
{
	while (window.isOpen())
	{
		events();
		if (crash())
		{
			break;
		}
		update();
		draw();
	}
}

void Game::events()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
					bird.fly();
				break;
			default:
				break;
		}
	}
}

bool Game::crash()
{
	sf::Rect bird_bounds = bird.body.getGlobalBounds();
	for (Obstacle* obstacle : obstacles)
	{
		sf::Rect top_bounds = obstacle->top.getGlobalBounds();
		sf::Rect bottom_bounds = obstacle->bottom.getGlobalBounds();

		if (bird_bounds.intersects(top_bounds))
			return true;
		if (bird_bounds.intersects(bottom_bounds))
			return true;
	}
	return false;
}

bool Game::section()
{
	if (!obstacles.empty())
	{
		if (obstacles.size() < NUM_SECTIONS + 1)
		{
			if (obstacles.front()->top.getPosition().x < next_section)
			{
				next_section = next_section - SECTION_GAP;
				return true;
			}
		}
	}
	return false;
}

bool Game::zero_reached()
{
	return obstacles.front()->top.getPosition().x < 0.0;
}

bool Game::destroy_obsacle()
{
	//Front obstacle got out of sight
	return obstacles.front()->top.getPosition().x < -OBST_WIDTH;
}

void Game::update()
{
	bird.update();

	if (obstacles.empty())
		obstacles.push_back(new Obstacle());

	if (section())
		obstacles.push_back(new Obstacle());

	if (destroy_obsacle())
	{
		next_section = 0;
		delete obstacles[0];
		obstacles.erase(obstacles.begin());
	}

	//Bird passed an obstacle completely, increase score
	for (int i = 0; i < (int)obstacles.size(); i++)
	{
		if (obstacles.at(i)->passed((int)bird.body.getPosition().x))
		{
			score++;
			break;
		}
	}

	//Update all obstacles' position
	for (int i = 0; i < (int)obstacles.size(); i++)
	{
		obstacles.at(i)->update();
	}
}

void Game::draw()
{
	window.clear();
	window.draw(background);
	window.draw(bird.body);

	for (int i = 0; i < (int)obstacles.size(); i++)
	{
		window.draw(obstacles.at(i)->top);
		window.draw(obstacles.at(i)->bottom);
	}

	window.display();
}