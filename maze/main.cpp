#include <chrono>
#include <iostream>
#include <thread>

#include "console_screen.h"
#include "random_mouse.h"
#include "wall_follower.h"
#include "tremaux.h"



int main()
{
	Maze maze;
// 	maze.load("data/overlook.maze");
// 	maze.load("data/tremaux_test.maze");
    maze.load("data/tremaux_test2.maze");

// 	Agent *agent = new RandomMouse(maze);
// 	Agent *agent = new WallFollower(maze);
	MappingAgent *agent = new Tremaux(maze);

#if 0
	// Version for step-by-step debugging and console output
	agent->setVerbose(true);
	for (size_t i = 0; i < 10; i++)
	{
//		agent->show();
		agent->showDiscovered();

		if (agent->isFinished())
			break;

		agent->nextStep();

		std::cout << "-----------------------------------------" << std::endl;
	}
#else
	// Final version for displaying the agent in action
	ConsoleScreen screen;
	for (size_t i = 0; i < 10000; i++)
	{
// 		agent->show(screen);
		agent->showDiscovered(screen);
		screen.put(IntVec2(maze.numrows()+1, 1), std::to_string(i));
		screen.refresh();
		if (agent->isFinished())
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(25));
// 		::getchar();

		agent->nextStep();
	}
	::getchar();
#endif

	delete agent;
	return 0;
}
