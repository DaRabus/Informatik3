#ifndef _POSE_H_
#define _POSE_H_



#include "intvec2.h"



class Pose
{
public:
	Pose();
	Pose(const Pose& other);
	Pose(const IntVec2& pos, const IntVec2& dir);
	Pose(const IntVec2& pos, ViewDir dir);

	IntVec2 getPos() const;
	IntVec2 getDir() const;
	IntVec2 getNextPos() const;

	void setPos(const IntVec2& p);

	void rotateLeft();
	void rotateRight();
	void moveForward();

	Pose& operator=(const Pose& other);

	friend std::ostream& operator<<(std::ostream& stream, const Pose& p);

private:
	IntVec2 pos;
	IntVec2 dir;
};



#endif	// _POSE_H_

