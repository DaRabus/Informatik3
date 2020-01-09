#include "mapping_agent.h"



MappingAgent::MappingAgent(const Maze &maze) :
	Agent(maze)
{
	mapSurroundings();
}



MappingAgent::MappingAgent(const Maze &maze, const Pose& pose) :
	Agent(maze, pose)
{
	mapSurroundings();
}



void MappingAgent::showDiscovered() const
{
	discovered_maze.show(estm_pose);
	std::cout << "Estimated pose " << estm_pose << std::endl;
}



void MappingAgent::showDiscovered(Screen &screen) const
{
	discovered_maze.show(screen);
	screen.put(estm_pose.getPos(),
		estm_pose.getDir().getViewDirChar());
}



void MappingAgent::turnLeft()
{
	Agent::turnLeft();
	estm_pose.rotateLeft();
}



void MappingAgent::turnAround()
{
	Agent::turnAround();
	estm_pose.rotateLeft();
	estm_pose.rotateLeft();
}



void MappingAgent::turnRight()
{
	Agent::turnRight();
	estm_pose.rotateRight();
}



bool MappingAgent::moveForward()
{
	// Update positions
	if (!Agent::moveForward())
	{
		return false;
	}
	estm_pose.moveForward();
	// Extend maze if necessary
	IntVec2 estm_pos = estm_pose.getPos();
	if (estm_pos.getRow() == 0)
	{
		discovered_maze.addEmptyLineTop(FieldType::Blocked);
		estm_pos += IntVec2(1, 0);
	}
	else if (estm_pos.getRow() == static_cast<int>(discovered_maze.numrows() - 1))
	{
		discovered_maze.addEmptyLineBottom(FieldType::Blocked);
	}
	else if (estm_pos.getCol() == 0)
	{
		discovered_maze.addEmptyLineLeft(FieldType::Blocked);
		estm_pos += IntVec2(0, 1);
	}
	else if (estm_pos.getCol() == static_cast<int>(discovered_maze.numcols() - 1))
	{
		discovered_maze.addEmptyLineRight(FieldType::Blocked);
	}
	estm_pose.setPos(estm_pos);
	// Mapping of new position
	mapSurroundings();
	return true;
}



void MappingAgent::mapSurroundings()
{
	for (size_t i = 0; i < 4; i++)
	{
		// Free means that there is no blocked wall ...
		if (frontIsFree())
		{
			// But still there can be other markings we do not want to delete
			if (discovered_maze.get(estm_pose.getNextPos()) == FieldType::Blocked)
			{
				discovered_maze.set(estm_pose.getNextPos(), FieldType::Free);
			}
		}
		turnLeft();
	}
}

