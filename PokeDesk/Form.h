#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <vector>
#include <string>
#include "Ability.h"
using namespace std;

class Form {
private:
	int formId;
	int pokeId;
	string name;
	vector<Ability> abilities;
	int stats[6];

public:
	Form();
	Form(string formName, int pkmnid, int formid);
	void addAbility(Ability ab);
	void addStats(int statId, int statVal);
	int getPokeId();
	void display();
};
#endif