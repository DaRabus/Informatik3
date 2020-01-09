#ifndef _RANDOM_MOUSE_H_
#define _RANDOM_MOUSE_H_



#include "agent.h"



class RandomMouse : public Agent
{
public:
	RandomMouse(const Maze &maze);
	RandomMouse(const Maze &maze, const Pose& pose);

	virtual void nextStep() override;

private:

};



#endif	// _RANDOM_MOUSE_H_
