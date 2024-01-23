#pragma once
#include "Classes.h"
#include "Enums.h"

class Dungeon{
	public:
	void go();
	int getFloor();
private:
	int floor=0;
	int steps=0;
	void shop(Player* play);
	void fight(Player* play, int dificulty);
};