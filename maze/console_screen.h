#ifndef _CONSOLESCREEN_H_
#define _CONSOLESCREEN_H_



#include <string>

#include "screen.h"



class ConsoleScreen : public Screen
{
public:
	ConsoleScreen();
	~ConsoleScreen();

	virtual void refresh() override;

	virtual void clear() override;
	virtual void put(const IntVec2 &vec, char c) override;
	virtual void put(const IntVec2 &vec, const std::string &str) override;
	virtual char get(const IntVec2 &vec) const override;
};



#endif	// _CONSOLESCREEN_H_
