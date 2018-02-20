#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Buff
{	
	friend class Buff_list;
protected:
	int percentage;
	int turns;
public:
	Buff(int per, int tur);
	int get_percentage();
	int get_turns();
	void move_turn();
};