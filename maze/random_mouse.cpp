#include "random_mouse.h"



RandomMouse::RandomMouse(const Maze &maze) :
	Agent(maze)
{
}



RandomMouse::RandomMouse(const Maze &maze, const Pose& pose) :
	Agent(maze, pose)
{
}



void RandomMouse::nextStep()
{
	std::vector<size_t> moves = getMoves();
	size_t moveIdx = rand() % moves.size();
	turn(moves[moveIdx]);
	moveForward();
}

