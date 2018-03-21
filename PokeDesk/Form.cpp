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
	name[0] = toupper(name[0]);
	cout << this->pokeId << ". " << this->name;
	cout << endl << endl << "Abilities: " << endl;
	for (unsigned int i = 0; i < abilities.size(); ++i) {
		abilities[i].display();
	}
	cout << endl << "BASE STATS: " << endl << "HP: " << stats[0] << endl << "Atk: ";
	cout << stats[1] << endl << "Def: " << stats[2] << endl << "SpAtk: ";
	cout << stats[3] << endl << "SpDef: " << stats[4] << endl << "Speed: ";
	cout << stats[5];
	cout << endl;
	cout << endl;
}