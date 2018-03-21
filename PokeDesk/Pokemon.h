#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <vector>
#include <string>
#include "Ability.h"
#include "Form.h"
using namespace std;


class Pokemon {
private:
	unsigned id;
	string name;
	vector<Ability> abilities;
	int stats[6];
	//form: new class. has own ability and stats. 
	//not all pokemon will have another form.
	//megas/alolans/seperate forms. ex: dusk lycanroc

public:
	vector<Form> alternates;
	Pokemon();
	Pokemon(unsigned num, string nam);
	string getName();
	void addAbility(Ability ab);
	void addStats(int statid, int statVal);
	void addForm(Form alt);
	void display();
};
#endif