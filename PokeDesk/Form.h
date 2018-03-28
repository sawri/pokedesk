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
	vector<string> types;
	int stats[6];

protected:
	vector<Ability> abilities;

public:
	
	Form();
	Form(string formName, int pkmnid, int formid);
	void addAbility(Ability ab);
	void addStats(int statId, int statVal);
	void addType(string typeName);
	int getPokeId();
	void display();
	void displayName();
	void displayAbils(int slot);
};
#endif