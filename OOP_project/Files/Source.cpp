#include <iostream>
#include <string>
#include "Item.h"
#include "Spell.h"
#include "Living1.h"


using namespace std;

int main(void)
{
	string a;
	cout << "Hello World!" << endl;
	cout << "Olympiakos" << endl;
	cout << "A change has been made!" << endl;
	Paladin pal;
	pal.print_stats();
	
	cin >> a;
	return 0;
}