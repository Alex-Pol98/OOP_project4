#include <iostream>
#include "Buff.h"

using namespace std;

Buff::Buff(int per, int tur) { percentage = per; turns = tur; }

int Buff::get_percentage() { return percentage; }
int Buff::get_turns() { return turns; }

void Buff::move_turn() { turns--; }