#include <ncurses.h>

#include "console_screen.h"



ConsoleScreen::ConsoleScreen()
{
	::initscr();
	::curs_set(0);	// hide cursor
}



ConsoleScreen::~ConsoleScreen()
{
	::endwin();
}



void ConsoleScreen::refresh()
{
	::refresh();
}



void ConsoleScreen::clear()
{
	::clear();
}



void ConsoleScreen::put(const IntVec2 &vec, char c)
{
	mvaddch(vec.getRow(), vec.getCol(), c);
}



void ConsoleScreen::put(const IntVec2 &vec, const std::string &str)
{
	::mvprintw(vec.getRow(), vec.getCol(), str.c_str());
}



char ConsoleScreen::get(const IntVec2 &vec) const
{
	return mvinch(vec.getRow(), vec.getCol()) & A_CHARTEXT;
}
