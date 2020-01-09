#ifndef _WALL_FOLLOWER_H_
#define _WALL_FOLLOWER_H_



#include "agent.h"



class WallFollower : public Agent
{
public:
	WallFollower(const Maze &maze);
	WallFollower(const Maze &maze, const Pose& pose);

	virtual void nextStep() override;

private:

	bool init = true;
};



#endif	// _WALL_FOLLOWER_H_

