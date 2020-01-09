#ifndef _SCREEN_H_
#define _SCREEN_H_



#include <string>
#include "intvec2.h"



class Screen
{
public:
	virtual void refresh() = 0;

	virtual void clear() = 0;
	virtual void put(const IntVec2 &vec, char c) = 0;
	virtual void put(const IntVec2 &vec, const std::string &str) = 0;
	virtual char get(const IntVec2 &vec) const = 0;
};



#endif	// _SCREEN_H_
