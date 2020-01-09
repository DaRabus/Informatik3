#ifndef _FIELD_TYPE_H_
#define _FIELD_TYPE_H_



enum class FieldType : char
{
	Blocked = '#',
	Free = ' ',

	StartEast = '>',
	StartNorth = '^',
	StartWest = '<',
	StartSouth = 'v',
	Finish = '$',

	TremauxMark1 = '.',
	TremauxMark2 = 'X',
};



#endif	// _FIELD_TYPE_H_

