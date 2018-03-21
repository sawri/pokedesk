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
	
	int stats[6];

public:
	vector<Ability> abilities;
	Form();
	Form(string formName, int pkmnid, int formid);
	void addAbility(Ability ab);
	void addStats(int statId, int statVal);
	int getPokeId();
	void display();
	void displayName();
	void displayAbils(int slot);
	void displayHP();
	void displayAtk();
	void displayDef();
	void displaySpAtk();
	void displaySpDef();
	void displaySpd();
};
#endif