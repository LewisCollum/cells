#pragma once

#include <bitset>

class Ship
{
	int x, y;
	short length;
	std::bitset<4> direction;
	bool sunk;

public:
	Ship();
};

