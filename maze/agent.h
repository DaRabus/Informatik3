#ifndef _AGENT_H_
#define _AGENT_H_



#include <optional>
#include <vector>

#include "maze.h"



class Agent
{
public:
	Agent(const Maze &full_maze);
	Agent(const Maze &full_maze, const Pose& pose);
	virtual ~Agent();

	void setVerbose(bool verbose);

	void show() const;
	void show(Screen &screen) const;

	virtual void nextStep() = 0;
	bool isFinished();

protected:
	bool verbose = false;

	virtual void turnLeft();
	virtual void turnAround();
	virtual void turnRight();
	virtual bool moveForward();

	bool frontIsFree();
	bool leftIsFree();
	bool backIsFree();
	bool rightIsFree();

	std::vector<size_t> getMoves() const;
	void turn(size_t numLeftTurns);

private:
	const Maze &full_maze;
	Pose real_pose;
	std::optional<IntVec2> finish = std::nullopt;
};



#endif	// _AGENT_H_
