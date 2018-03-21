#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Ability {
private:
	//some pokemon have same abilities. there will be some w/ same name and id.
	//but the slot may differ.
	string name; //name of ability
	int id; //specify which ability it is
	bool hidden;
	int slot; //slot 1,2,3. 3 for hidden
	//TO-DO: add descriptions of abilities.
public:
	Ability();
	Ability(int idNum, bool isHidden, int slotNum, string abName);
	void addName(string abName);
	void display();
};
#endif
