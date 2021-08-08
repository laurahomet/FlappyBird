#include "../include/Game.hpp"

int main()
{
	util::Platform platform;
    
	Game game("Flappy Bird");
	game.mainloop();

	return 0;
}
