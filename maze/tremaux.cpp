#include <algorithm>

#include "tremaux.h"



Tremaux::Tremaux(const Maze &maze) :
	MappingAgent(maze)
{
}



Tremaux::Tremaux(const Maze &maze, const Pose& pose) :
	MappingAgent(maze, pose)
{
}



void Tremaux::nextStep()
{
	std::vector<size_t> moves = getMoves();
	if (verbose)
	{
		std::cout << "Number of moves: " << moves.size() << std::endl;
	}
	// Single option: probably a dead end
	if (moves.size() == 1)
	{
		turn(moves[0]);
		moveForward();
		return;
	}
	// Remove move that lead us to this crossing from list
	auto backIt = std::find(moves.begin(), moves.end(), numLeftTurnsToTurnAround); // TODO: Incorrect...
	moves.erase(backIt);
	// Two options minus the one we came from: normal passage way
	if (moves.size() == 1)
	{
		turn(moves[0]);
		moveForward();
		return;
	}
	// A crossing
	handleCrossing(moves);
}



void Tremaux::handleCrossing(const std::vector<size_t> &moves)
{
	// Get marks of passages
	std::vector<FieldType> marks(moves.size(), FieldType::Free);
	bool crossingIsNew = true;
	for (size_t i = 0; i < moves.size(); i++)
	{
		marks[i] = getMark(moves[i]);
		if ((marks[i] == FieldType::TremauxMark1) ||
			(marks[i] == FieldType::TremauxMark2))
		{
			crossingIsNew = false;
		}
	}
	if (verbose)
	{
		std::cout << "Moves and marks: ";
		for (size_t i = 0; i < moves.size(); i++)
		{
			std::cout << moves[i] << "(" << static_cast<char>(marks[i]) << ") ";
		}
		std::cout << std::endl;
	}
	// If the crossing is completely unmarked: pick one passage and
	// mark in and out with first marker
	if (crossingIsNew)
	{
		setMark(numLeftTurnsToTurnAround, FieldType::TremauxMark1); // in
		setMark(moves[0], FieldType::TremauxMark1); // out
		turn(moves[0]);
		moveForward();
		return;
	}
	// If passage that lead to crossing was unmarked, turn around
	if (getMark(numLeftTurnsToTurnAround) == FieldType::Free)
	{
		setMark(numLeftTurnsToTurnAround, FieldType::TremauxMark2); // in and out
		turn(numLeftTurnsToTurnAround);
		moveForward();
		return;
	}
	// If one of the outgoing passages is unmarked, use it
	for (size_t i = 0; i < moves.size(); i++)
	{
		if (marks[i] == FieldType::Free)
		{
			setMark(numLeftTurnsToTurnAround, FieldType::TremauxMark2); // in
			setMark(moves[i], FieldType::TremauxMark1); // out
			turn(moves[i]);
			moveForward();
			return;
		}
	}
	// If one of the outgoing passages is marked first time, use it
	for (size_t i = 0; i < moves.size(); i++)
	{
		if (marks[i] == FieldType::TremauxMark1)
		{
			setMark(numLeftTurnsToTurnAround, FieldType::TremauxMark2); // in
			setMark(moves[i], FieldType::TremauxMark2); // out
			turn(moves[i]);
			moveForward();
			return;
		}
	}
}



FieldType Tremaux::getMark(size_t numLeftTurns) const
{
	Pose pose(estm_pose);
	for (size_t i = 0; i < numLeftTurns; i++)
	{
		pose.rotateLeft();
	}
	return discovered_maze.get(pose.getNextPos());
}



void Tremaux::setMark(size_t numLeftTurns, FieldType field)
{
	Pose pose(estm_pose);
	for (size_t i = 0; i < numLeftTurns; i++)
	{
		pose.rotateLeft();
	}
	if (verbose)
	{
		std::cout << "setMark '" << static_cast<char>(field) << "' at " <<
			pose << " (" << numLeftTurns << "x left rotated)" << std::endl;
	}
	discovered_maze.set(pose.getNextPos(), field);
}

