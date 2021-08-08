#include "Constants.hpp"
#include <iostream>

/**********************************************************
 *  @brief   Pair of pipes: top pipe faces down, bottom
 * 			 pipe faces up.
 *********************************************************/
class Obstacle
{
public:
	/**********************************************************
	 *  @brief   Top pipe of the obstacle.
	 *********************************************************/
	sf::Sprite top;

	/**********************************************************
	 *  @brief   Bottom pipe of the obstacle.
	 *********************************************************/
	sf::Sprite bottom;

	/**********************************************************
	 *  @brief   Constructor of the class Obstacle.
	 *  @details An obstacle is a pair of two pipes.
	 * 			 The constructor loads the obstacle image for both
	 * 			 top and bottom pipes, sets their position
	 * 			 randomly within given boundaries, and sets the
	 * 			 texture and scale of the pipes.
	 *********************************************************/
	Obstacle();

	/**********************************************************
	 *  @brief   Update the position of the obstacle.
	 *  @details Moves both top and bottom pipes to the left,
	 * 			 according to a pre-defined obstacle velocity.
	 *********************************************************/
	void update();

	/**********************************************************
	 *  @brief   Detect section edge.
	 *  @details Returns true whenever an obstacle reaches a
	 * 			 section edge, as per the pre-defined section
	 * 			 dimensions.
	 *********************************************************/
	bool section();

	/**********************************************************
	 *  @brief   Detect window edge.
	 *  @details Returns true whenever an obstacle reaches the
	 * 			 left-most position so that it is not visible
	 * 			 in the window anymore.
	 *********************************************************/
	bool disappear();

	/**********************************************************
	 *  @brief   Detect threshold pass.
	 *  @details Returns true whenever the obstacle passed a
	 * 			 given position in the horizontal axis.
	 *  @param   threshold Position to evaluate against
	 *********************************************************/
	bool passed(int threshold);

private:
	sf::Texture obst_top;
	sf::Texture obst_bottom;
	bool active = true;
	float next_section = WIN_WIDTH - SECTION_GAP;

	void setup();
};