#include "pose.h"



Pose::Pose()
{
}



Pose::Pose(const Pose& other) :
	pos(other.pos),
	dir(other.dir)
{
}



Pose::Pose(const IntVec2& pos, const IntVec2& dir) :
	pos(pos),
	dir(dir)
{
}



Pose::Pose(const IntVec2& pos, ViewDir dir) :
	pos(pos),
	dir(dir)
{
}



IntVec2 Pose::getPos() const
{
	return pos;
}



IntVec2 Pose::getDir() const
{
	return dir;
}



IntVec2 Pose::getNextPos() const
{
	return pos + dir;
}



void Pose::setPos(const IntVec2& p)
{
	pos = p;
}



void Pose::rotateLeft()
{
	dir.rotateLeft();
}



void Pose::rotateRight()
{
	dir.rotateRight();
}



void Pose::moveForward()
{
	pos = pos + dir;
}



Pose& Pose::operator=(const Pose& other)
{
	if (this != &other)
	{
		pos = other.pos;
		dir = other.dir;
	}
	return *this;
}



std::ostream& operator<<(std::ostream& stream, const Pose& p)
{
	stream << "[ " << p.pos << ", " << p.dir << " ]";
	return stream;
}

