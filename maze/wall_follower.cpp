#include "wall_follower.h"



WallFollower::WallFollower(const Maze &maze) :
	Agent(maze)
{
}



WallFollower::WallFollower(const Maze &maze, const Pose& pose) :
	Agent(maze, pose)
{
}



void WallFollower::nextStep()
{
	if (init)
	{
		// Find a wall and rotate that the wall is to our left
		if (!frontIsFree())
		{
			turnRight();
			init = false;
			return;
		}
		if (!leftIsFree())
		{
			init = false;
			return;
		}
		if (!backIsFree())
		{
			turnLeft();
			init = false;
			return;
		}
		if (!rightIsFree())
		{
			turnAround();
			init = false;
			return;
		}
		// No wall found: Move forward
		moveForward();
	}
	else
	{
		if (leftIsFree())
		{
			turnLeft();
			moveForward();
		}
		else
		{
			if (!moveForward())
			{
				turnRight();
			}
		}
	}
}

