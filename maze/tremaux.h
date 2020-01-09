#ifndef _TREMAUX_H_
#define _TREMAUX_H_



#include "mapping_agent.h"



class Tremaux : public MappingAgent
{
public:
	Tremaux(const Maze &maze);
	Tremaux(const Maze &maze, const Pose& pose);

	virtual void nextStep() override;

private:
	
	const size_t numLeftTurnsToTurnAround = 2;

	void handleCrossing(const std::vector<size_t> &moves);
	FieldType getMark(size_t numLeftTurns) const;
	void setMark(size_t numLeftTurns, FieldType field);
};



#endif	// _TREMAUX_H_

