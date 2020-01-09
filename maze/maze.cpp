#include <iostream>
#include <fstream>
#include <stdexcept>
#include "maze.h"



Maze::Maze()
{
}



Maze::Maze(size_t numrows, size_t numcols, FieldType field)
{
	cols = numcols;
	for (size_t r = 0; r < numrows; r++)
	{
		cells.insert(cells.end(), std::string(numcols, static_cast<char>(field)));
	}
}



size_t Maze::numrows() const
{
	return cells.size();
}



size_t Maze::numcols() const
{
	return cols;
}



IntVec2 Maze::size() const
{
	return IntVec2(numrows(), numcols());
}



void Maze::clear()
{
	cells.clear();
	cols = 0;
}



void Maze::load(const std::string &filename)
{
	clear();
	std::ifstream f(filename);
	if (!f.is_open())
	{
		throw std::runtime_error("Unable to open file");
	}

	std::string line;
	bool is_first_line = true;
	while (std::getline(f, line))
	{
		cells.push_back(line);
		if (is_first_line)
		{
			cols = line.size();
		}
		else
		{
			if (cols != line.size())
			{
				clear();
				throw std::runtime_error("Not all lines have same width");
			}
		}
	}
}



void Maze::show(const Pose &pose) const
{
	for (size_t r = 0; r < numrows(); r++)
	{
		for (size_t c = 0; c < numcols(); c++)
		{
			if (pose.getPos() == IntVec2(r, c))
			{
				std::cout << pose.getDir().getViewDirChar();
			}
			else
			{
				std::cout << cells[r][c];
			}
		}
		std::cout << std::endl;
	}
}



void Maze::show(Screen &screen) const
{
	size_t row = 0;
	for (auto &line : cells)
	{
		screen.put(IntVec2(row, 0), line);
		row++;
	}
}



std::optional<IntVec2> Maze::find(FieldType field) const
{
	for (size_t r = 0; r < numrows(); r++)
	{
		size_t c = cells[r].find(static_cast<char>(field));
		if (c != std::string::npos)
		{
			return IntVec2(r, c);
		}
	}
	return std::nullopt;
}



FieldType Maze::get(const IntVec2 &vec) const
{
	if ((vec.getRow() < 0) ||
		(static_cast<size_t>(vec.getRow()) >= cells.size()) ||
		(vec.getCol() < 0) ||
		(static_cast<size_t>(vec.getCol()) >= cells[vec.getRow()].size()))
	{
		throw std::runtime_error("Reading from an invalid field");
	}
	return static_cast<FieldType>(cells[vec.getRow()][vec.getCol()]);
}



std::vector<size_t> Maze::getMoves(const Pose &pose) const
{
	std::vector<size_t> result;
	Pose poses(pose);
	for (size_t i = 0; i < 4; i++)
	{
		if (get(poses.getNextPos()) != FieldType::Blocked)
		{
			result.push_back(i);
		}
		poses.rotateLeft();
	}
	return result;
}



void Maze::set(const IntVec2 &vec, FieldType field)
{
	if ((vec.getRow() < 0) ||
		(static_cast<size_t>(vec.getRow()) >= cells.size()) ||
		(vec.getCol() < 0) ||
		(static_cast<size_t>(vec.getCol()) >= cells[vec.getRow()].size()))
	{
		throw std::runtime_error("Writing to an invalid field");
	}
	cells[vec.getRow()][vec.getCol()] = static_cast<char>(field);
}



std::ostream& operator<<(std::ostream& stream, const Maze& maze)
{
	for (auto &line : maze.cells)
	{
		stream << line << std::endl;
	}
	return stream;
}



void Maze::addEmptyLineTop(FieldType field)
{
	cells.insert(cells.begin(), std::string(numcols(), static_cast<char>(field)));
}



void Maze::addEmptyLineBottom(FieldType field)
{
	cells.insert(cells.end(), std::string(numcols(), static_cast<char>(field)));
}



void Maze::addEmptyLineLeft(FieldType field)
{
	for (auto &line : cells)
	{
		line = static_cast<char>(field) + line;
	}
	cols++;
}



void Maze::addEmptyLineRight(FieldType field)
{
	for (auto &line : cells)
	{
		line = line + static_cast<char>(field);
	}
	cols++;
}

