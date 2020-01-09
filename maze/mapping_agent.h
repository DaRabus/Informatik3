#ifndef _MAPPING_AGENT_H_
#define _MAPPING_AGENT_H_



#include "agent.h"



class MappingAgent : public Agent
{
public:
	MappingAgent(const Maze &maze);
	MappingAgent(const Maze &maze, const Pose& pose);

	void showDiscovered() const;
	void showDiscovered(Screen &screen) const;

protected:
	virtual void turnLeft() override;
	virtual void turnAround() override;
	virtual void turnRight() override;
	virtual bool moveForward() override;

	Maze discovered_maze = Maze(3, 3, FieldType::Blocked);
	Pose estm_pose = Pose(IntVec2(1,1), ViewDir::East);

private:
	void mapSurroundings();
};



#endif	// _MAPPING_AGENT_H_

