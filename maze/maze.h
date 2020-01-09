#ifndef _MAZE_H_
#define _MAZE_H_



#include <optional>
#include <string>
#include <vector>

#include "field_type.h"
#include "pose.h"
#include "screen.h"



class Maze
{
public:
	Maze();
	Maze(size_t numrows, size_t numcols, FieldType field);

	size_t numrows() const;
	size_t numcols() const;
	IntVec2 size() const;

	void clear();
	void load(const std::string &filename);
	void show(const Pose &pose) const;
	void show(Screen &screen) const;

	std::optional<IntVec2> find(FieldType field) const;

	FieldType get(const IntVec2 &vec) const;
	std::vector<size_t> getMoves(const Pose &pose) const;

	void set(const IntVec2 &vec, FieldType field);

	friend std::ostream& operator<<(std::ostream& stream, const Maze& maze);

	void addEmptyLineTop(FieldType field);
	void addEmptyLineBottom(FieldType field);
	void addEmptyLineLeft(FieldType field);
	void addEmptyLineRight(FieldType field);

private:
	size_t cols = 0;
	std::vector<std::string> cells;
};



#endif	// _MAZE_H_
