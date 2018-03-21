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
	int counter = 0;
	if (alternates.size() > 0) {
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			cout << "\t\t\t";
			alternates[i].displayName();
		}
	}
	cout << endl << endl << "ABILITIES: " << endl;
	if (!alternates.empty()) {
		if (alternates.size() == 1) {
			if (alternates[0].abilities.size() == abilities.size()) {
				for (unsigned int j = 0; j < abilities.size(); ++j) {
					abilities[j].display();
					cout << "\t\t\t";
					alternates[0].abilities[j].display();
					cout << endl;
				}
			}
			else if (alternates[0].abilities.size() == 1) {
				abilities[0].display();
				cout << "\t\t\t";
				alternates[0].abilities[0].display();
				cout << endl;
				for (unsigned int j = 1; j < abilities.size(); ++j) {
					abilities[j].display();
				}
				cout << endl;
			}
		}
		if (alternates.size() == 2) {
			if (alternates[0].abilities.size() == abilities.size()) {
				for (unsigned int j = 0; j < abilities.size(); ++j) {
					abilities[j].display();
					cout << "\t\t\t";
					alternates[0].abilities[j].display();
					cout << "\t\t\t";
					alternates[1].abilities[j].display();
					cout << endl;
				}
			}
			else if (alternates[0].abilities.size() == 1) {
				abilities[0].display();
				cout << "\t\t\t";
				alternates[0].abilities[0].display();
				cout << "\t\t\t\t";
				alternates[1].abilities[0].display();
				cout << endl;
				for (unsigned int j = 1; j < abilities.size(); ++j) {
					abilities[j].display();
				}
				cout << endl;
			}
		}
		if (alternates.size() == 3) {
			if (alternates[0].abilities.size() == abilities.size()) {
				for (unsigned int j = 0; j < abilities.size(); ++j) {
					abilities[j].display();
					cout << "\t\t\t";
					alternates[0].abilities[j].display();
					cout << "\t\t\t\t";
					alternates[1].abilities[j].display();
					cout << "\t\t\t\t";
					alternates[2].abilities[j].display();
					cout << endl;
				}
			}
		}

	}
	else {
		for (unsigned int i = 0; i < abilities.size(); ++i) {
			abilities[i].display();
			cout << endl;
		}
	}
	if (!alternates.empty()) {
		cout << endl << "BASE STATS: " << "\nHP: " << stats[0];
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			cout << "\t\t\t\t HP: ";
			alternates[i].displayHP();
		}
		cout << "\nAtk: " << stats[1];
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			cout << "\t\t\t\t Atk: ";
			alternates[i].displayAtk();
		}
		cout << "\nDef: " << stats[2];
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			cout << "\t\t\t\t Def: ";
			alternates[i].displayDef();
		}
		cout << "\nSpAtk: " << stats[3];
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			cout << "\t\t\t SpAtk: ";
			alternates[i].displaySpAtk();
		}
		cout << "\nSpDef: " << stats[4];
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			cout << "\t\t\t SpDef: ";
			alternates[i].displaySpDef();
		}
		cout << "\nSpeed: " << stats[5];
		for (unsigned int i = 0; i < alternates.size(); ++i) {
			cout << "\t\t\t Speed: ";
			alternates[i].displaySpd();
		}
		cout << endl;
	}
	else {
		cout << endl << "BASE STATS: " << endl << "HP: " << stats[0] << endl << "Atk: ";
		cout << stats[1] << endl << "Def: " << stats[2] << endl << "SpAtk: ";
		cout << stats[3] << endl << "SpDef: " << stats[4] << endl << "Speed: ";
		cout << stats[5];
		cout << endl;
		cout << endl;
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
