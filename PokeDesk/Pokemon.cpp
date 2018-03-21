#include "stdafx.h"
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

void Pokemon::addStats(int statid, int statVal) {
	stats[statid - 1] = statVal;
}

void Pokemon::display() {
	name[0] = toupper(name[0]);
	cout << this->id << ". " << this->name;
	cout << endl << endl << "ABILITIES: " << endl;
	for (unsigned int i = 0; i < abilities.size(); ++i) {
		abilities[i].display();
	}
	cout << endl << "BASE STATS: " << endl << "HP: " << stats[0] << endl << "Atk: ";
	cout << stats[1] << endl << "Def: " << stats[2] << endl << "SpAtk: ";
	cout << stats[3] << endl << "SpDef: " << stats[4] << endl << "Speed: ";
	cout << stats[5];
	cout << endl;
	cout << endl;
	if (alternates.size() > 0) {
		cout << "[ALTERNATE FORM(S)]: " << endl;
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			alternates[i].display();
			cout << endl;
		}
	}
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
