#include "stdafx.h"
#include "Form.h"
#include "Ability.h"

using namespace std;

Form::Form() {
	formId = 0;
	name = "";
	pokeId = 0;
}
Form::Form(string formName, int pkmnid, int formid) {
	name = formName;
	formId = formid;
	pokeId = pkmnid;
}
void Form::addType(string typeName) {
	types.push_back(typeName);
}
void Form::addAbility(Ability ab) {
	abilities.push_back(ab);
}
void Form::addStats(int statId, int statVal) {
	stats[statId - 1] = statVal;
}
int Form::getPokeId() {
	return pokeId;
}
void Form::display() {
	string temp = name;
	name[0] = toupper(name[0]);
	for (unsigned int i = 0; i < name.size(); ++i) {
		if (name[i] == '-') {
			name[i] = ' ';
			name[i + 1] = toupper(name[i + 1]);
		}
	}
	cout << this->name;
	cout << endl << "Type: " << types[0];
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
	cout << endl;
	name = temp;
}
void Form::displayName() {
	name[0] = toupper(name[0]);
	cout << this->pokeId << ". " << this->name;
}
void Form::displayAbils(int slot) {
	abilities[slot].display();
}