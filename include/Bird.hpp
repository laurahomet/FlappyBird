#include "Constants.hpp"
#include <iostream>

/**********************************************************
 *  @brief   Main character of the game.
 *********************************************************/
class Bird
{
public:
	/**********************************************************
	 *  @brief   Body of the bird.
	 *********************************************************/
	sf::Sprite body;

	/**********************************************************
	 *  @brief   Constructor of Bird
	 *  @details Initializes the bird in terms velocity,
	 * 			 acceleration, and max flying position. Loads
	 * 			 the bird image and sets its position, texture,
	 * 			 and scale.
	 *********************************************************/
	Bird();

	/**********************************************************
	 *  @brief   Fly command
	 *  @details Sets the bird's acceleration to the predefined
	 * 			 acceleration value to cause flying illusion.
	 * 			 Computes the maximum vertical position the bird
	 * 			 can reach according to its current position.
	 *********************************************************/
	void fly();

	/**********************************************************
	 *  @brief   Fall command
	 *  @details Sets the bird's acceleration to the predefined
	 * 			 acceleration value to cause falling illusion.
	 *********************************************************/
	void fall();

	/**********************************************************
	 *  @brief   Update command.
	 *  @details Updates the velocity of the bird and moves
	 *           it accordingly. Min and max boundaries are
	 *           defined to keep the velocity within a range.
	 *           Evaluates the position of the bird and starts
	 *           falling if applicable.
	 *********************************************************/
	void update();

private:
	sf::Texture bird_fly;
	sf::Texture bird_fall;
	float acceleration;
	float velocity;
	int start_fall;

	void setup();
};