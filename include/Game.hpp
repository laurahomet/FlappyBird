#include "../src/Platform/Platform.hpp"
#include "Bird.hpp"
#include "Constants.hpp"
#include "Obstacle.hpp"
#include <iostream>
#include <vector>

/**********************************************************
 *  @brief   Where game logic happens.
 *********************************************************/
class Game
{
public:
	/**********************************************************
	 *  @brief   Number of pipes the bird has passed.
	 *  @details Increses whenever the back of the bird passes
	 * 			 the right side of a pair of an obstacle.
	 *********************************************************/
	int score = 0;

	/**********************************************************
	 *  @brief   Constructor of the class Game.
	 *  @details Builds the window with a given title, loads
	 * 			 the background image, sets up the background
	 * 	 		 scale and texture, and starts the bird's
	 * 			 movement to falling trajectory.
	 *********************************************************/
	Game(const char* title);

	/**********************************************************
	 *  @brief   Destructor of the class Game.
	 *  @details Prints the final score.
	 *********************************************************/
	~Game();

	/**********************************************************
	 *  @brief   Loop game logic.
	 *  @details Whenever the window is open, checks for events,
	 * 			 updates the logic of the game, and re-draws the
	 * 			 window and the elements in it.
	 * 			 Loop breaks when a collision between the bird
	 * 			 and an object is detected.
	 *********************************************************/
	void mainloop();

private:
	Bird bird;
	sf::RenderWindow window;
	sf::Texture background_img;
	sf::Sprite background;
	std::vector<Obstacle*> obstacles;
	float next_section = WIN_WIDTH - SECTION_GAP;

	void setup(const char* title);
	void events();
	bool crash();
	bool section();
	bool zero_reached();
	bool destroy_obsacle();
	void update();
	void draw();
};