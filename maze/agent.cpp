#include "agent.h"



Agent::Agent(const Maze &full_maze) :
	full_maze(full_maze)
{
	finish = full_maze.find(FieldType::Finish);

	std::optional<IntVec2> pos;	
	pos = full_maze.find(FieldType::StartEast);
	if (pos)
	{
		real_pose = Pose(*pos, ViewDir::East);
		return;
	}
	pos = full_maze.find(FieldType::StartNorth);
	if (pos)
	{
		real_pose = Pose(*pos, ViewDir::North);
		return;
	}
	pos = full_maze.find(FieldType::StartWest);
	if (pos)
	{
		real_pose = Pose(*pos, ViewDir::West);
		return;
	}
	pos = full_maze.find(FieldType::StartSouth);
	if (pos)
	{
		real_pose = Pose(*pos, ViewDir::South);
		return;
	}
}



Agent::Agent(const Maze &full_maze, const Pose& pose) :
	full_maze(full_maze),
	real_pose(pose)
{
}



Agent::~Agent()
{
}



void Agent::setVerbose(bool verbose)
{
	this->verbose = verbose;
}



void Agent::show() const
{
	full_maze.show(real_pose);
	std::cout << "Real pose " << real_pose << std::endl;
}



void Agent::show(Screen &screen) const
{
	full_maze.show(screen);
	screen.put(real_pose.getPos(),
		real_pose.getDir().getViewDirChar());
}



bool Agent::isFinished()
{
	if (finish)
	{
		if (real_pose.getPos() == *finish)
		{
			return true;
		}
	}
	return false;
}



void Agent::turnLeft()
{
	real_pose.rotateLeft();
}



void Agent::turnAround()
{
	real_pose.rotateLeft();
	real_pose.rotateLeft();
}



void Agent::turnRight()
{
	real_pose.rotateRight();
}



bool Agent::moveForward()
{
	FieldType field = full_maze.get(real_pose.getNextPos());
	if (field == FieldType::Blocked)
	{
		return false;
	}
	real_pose.moveForward();
	return true;
}



bool Agent::frontIsFree()
{
	return full_maze.get(real_pose.getNextPos()) != FieldType::Blocked;
}



bool Agent::leftIsFree()
{	
	Pose pose(real_pose);
	pose.rotateLeft();
	return full_maze.get(pose.getNextPos()) != FieldType::Blocked;
}



bool Agent::backIsFree()
{
	Pose pose(real_pose);
	pose.rotateLeft();
	pose.rotateLeft();
	return full_maze.get(pose.getNextPos()) != FieldType::Blocked;
}



bool Agent::rightIsFree()
{
	Pose pose(real_pose);
	pose.rotateRight();
	return full_maze.get(pose.getNextPos()) != FieldType::Blocked;
}



std::vector<size_t> Agent::getMoves() const
{
	return full_maze.getMoves(real_pose);
}



void Agent::turn(size_t numLeftTurns)
{
	for (size_t i = 0; i < numLeftTurns; i++)
	{
		turnLeft();
	}
}

