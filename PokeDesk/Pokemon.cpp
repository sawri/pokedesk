#include "stdafx.h"
#include <iomanip>
#include "Pokemon.h"
#include "Ability.h"

using namespace std;

Pokemon::Pokemon() {
	name = "";
	id = 0;
	
}
Pokemon::Pokemon(unsigned num, string nam) {
	id = num;
	name = nam;
}
void Pokemon::addType(string typeName) {
	types.push_back(typeName);
}
void Pokemon::addStats(int statid, int statVal) {
	stats[statid - 1] = statVal;
}

void Pokemon::display() {
	string temp = name;
	name[0] = toupper(name[0]);
	cout << this->id << ". " << this->name << endl;
	cout << "Type: " << types[0];
	if (types.size() == 2) {
		cout << "/" << types[1];
	}
	cout << endl << endl << "ABILITIES: " << endl;
	for (unsigned int i = 0; i < abilities.size(); ++i) {
		abilities[i].display();
	}
	cout << endl << "BASE STATS: " << endl << "HP: " << stats[0] << endl << "Atk: ";
	cout << stats[1] << endl << "Def: " << stats[2] << endl << "SpAtk: ";
	cout << stats[3] << endl << "SpDef: " << stats[4] << endl << "Speed: ";
	cout << stats[5];
	cout << endl << endl;
	cout << "Total: " << stats[0] + stats[1] + stats[2] + stats[3] + stats[4] + stats[5];
	cout << endl << endl;
	if (alternates.size() > 0) {
		cout << "ALTERNATE FORM(S): " << endl;
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			alternates[i].display();
			cout << endl;
		}
	}
	name = temp;
}

void Pokemon::addForm(Form alt) {
	alternates.push_back(alt);
}
string Pokemon::getName() {
	return this->name;
}
void Pokemon::addAbility(Ability ab) {
	abilities.push_back(ab);
}
