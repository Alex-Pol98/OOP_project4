#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Buff
{	
	friend class Buff_list;
protected:
	int percentage;  //Determines how much will the damage be multiplied (ex. 5->+5%)
	int turns;       //Deterrmines how many turns will the buff last
public:
	Buff(int per, int tur);
	int get_percentage();
	int get_turns();
	void move_turn();  //Decreases the turn by 1
};