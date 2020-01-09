#include "intvec2.h"



IntVec2::IntVec2()
{
}



IntVec2::IntVec2(const IntVec2& other) :
	row(other.row),
	col(other.col)
{
}



IntVec2::IntVec2(int r, int c) :
	row(r),
	col(c)
{
}



IntVec2::IntVec2(ViewDir dir)
{
	switch (dir)
	{
		case ViewDir::East:
		{
			row = 0;
			col = 1;
			break;
		}
		case ViewDir::North:
		{
			row = -1;
			col = 0;
			break;
		}
		case ViewDir::West:
		{
			row = 0;
			col = -1;
			break;
		}
		case ViewDir::South:
		{
			row = 1;
			col = 0;
			break;
		}
		default:
		{
			throw std::runtime_error("Invalid ViewDir");
		}
	}
}



int IntVec2::getRow() const
{
	return row;
}



int IntVec2::getCol() const
{
	return col;
}



ViewDir IntVec2::getViewDir() const
{
	if (row == 0)
	{
		if (col > 0)
		{
			return ViewDir::East;
		}
		else
		{
			return ViewDir::West;
		}
	}
	if (col == 0)
	{
		if (row > 0)
		{
			return ViewDir::South;
		}
		else
		{
			return ViewDir::North;
		}
	}
	throw std::runtime_error("Invalid ViewDir");
}



char IntVec2::getViewDirChar() const
{
	const char *dirChars = ">^<v";
	return dirChars[static_cast<int>(getViewDir())];
}



void IntVec2::rotateLeft()
{
	int oldrow = row;
	row = -col;
	col = oldrow;
}



void IntVec2::rotateLeft(unsigned int num)
{
	for (unsigned int i = 0; i < num; i++)
	{
		rotateLeft();
	}
}



void IntVec2::rotateRight()
{
	int oldrow = row;
	row = col;
	col = -oldrow;
}



void IntVec2::rotateRight(unsigned int num)
{
	for (unsigned int i = 0; i < num; i++)
	{
		rotateRight();
	}
}



IntVec2& IntVec2::operator=(const IntVec2& other)
{
	if (this != &other)
	{
		row = other.row;
		col = other.col;
	}
	return *this;
}



bool IntVec2::operator==(const IntVec2& other)
{
	return (row == other.row) && (col == other.col);
}



bool IntVec2::operator!=(const IntVec2& other)
{
	return !operator==(other);
}



IntVec2 IntVec2::operator+(const IntVec2& other) const
{
	return IntVec2(row + other.row, col + other.col);
}



IntVec2& IntVec2::operator+=(const IntVec2& other)
{
	row += other.row;
	col += other.col;
	return *this;
}



std::ostream& operator<<(std::ostream& stream, const IntVec2& vec)
{
	stream << "(" << vec.row << ", " << vec.col << ")";
	return stream;
}

