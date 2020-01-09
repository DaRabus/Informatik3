#ifndef _INTVEC2_H_
#define _INTVEC2_H_



#include <iostream>



enum class ViewDir
{
	East = 0,
	North,
	West,
	South
};



class IntVec2
{
public:
	IntVec2();
	IntVec2(const IntVec2& other);
	IntVec2(int r, int c);
	IntVec2(ViewDir dir);

	int getRow() const;
	int getCol() const;
	ViewDir getViewDir() const;
	char getViewDirChar() const;

	void rotateLeft();
	void rotateLeft(unsigned int num);
	void rotateRight();
	void rotateRight(unsigned int num);

	IntVec2& operator=(const IntVec2& other);

	bool operator==(const IntVec2& other);
	bool operator!=(const IntVec2& other);

	IntVec2 operator+(const IntVec2& other) const;
	IntVec2& operator+=(const IntVec2& other);

	friend std::ostream& operator<<(std::ostream& stream, const IntVec2& vec);

private:
	int row = 0;
	int col = 0;
};



#endif	// _INTVEC2_H_

