#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "pokemon.h"
#include "Ability.h"
#include "Form.h"
#include "Description.h"
using namespace std;
Pokemon pokes[807]; //array of all pokemon
string abilities[233]; //array of abilities
string abildescs[233]; //array of ability descriptions
//Description descrs[233];
Form alternates[157];
void loadPokemon() {
	int tempid = 0;
	string tempname = "";
	ifstream fin;
	fin.open("pokemondatabase.txt");
	if (!fin.is_open()) {
		cout << "There was an error opening the database file." << endl;
		exit(1);
	}
	//open our database correctly
	for (int i = 0; i < 807; ++i) {
		fin >> tempid >> tempname;
		Pokemon temp(tempid, tempname);
		pokes[i] = temp;
	} //fills array w/ pokemon names and numbers cuz that's all I have for now :'(
	fin.close();
}
void loadAbilNames() {
	ifstream fin;
	int counter = 0;
	string tempname = "";
	string tempdesc = "";
	fin.open("abilitynames.txt");
	if (!fin.is_open()) {
		cout << "There was an error opening the ability names file." << endl;
		exit(1);
	}
	for (int i = 0; i < 233; ++i) {
		fin >> counter >> tempname >> tempdesc;
		abilities[i] = tempname;
		abildescs[i] = tempdesc;
	}
	fin.close();
}
void loadAbils() {
	ifstream fin;
	int tempid = 0;
	bool tempBool = true;
	int tempSlot = 0;
	fin.open("pokemonabilities.txt");
	if (!fin.is_open()) {
		cout << "There was an error opening the abilities file." << endl;
		exit(1);
	}
	int pokeId = 0;
	//pokemon ID > ability ID > hidden > slot
	for (int i = 0; i < 1931; ++i) {

		fin >> pokeId >> tempid >> tempBool >> tempSlot;
		string nameToAdd = abilities[tempid - 1];
		string descToAdd = abildescs[tempid - 1];
		Ability temp(tempid, tempBool, tempSlot, nameToAdd);
		pokes[pokeId - 1].addAbility(temp);
	}
	fin.close();
}
void loadStats() {
	ifstream fin;
	int pokeid = 0;
	int statNum = 0;
	int statVal = 0;
	fin.open("stats.txt");
	if (!fin.is_open()) {
		cout << "There was an error opening the stats database." << endl;
		exit(1);
	}
	for (int i = 0; i < 4842; ++i) {
		fin >> pokeid >> statNum >> statVal;
		pokes[pokeid - 1].addStats(statNum, statVal);
	}
	fin.close();
}
void loadTypes() {
	ifstream fin;
	fin.open("pokemontypes.txt");
	int pokeid = 0;
	string type = "";
	for (int i = 0; i < 1212; ++i) {
		fin >> pokeid >> type;
		pokes[pokeid - 1].addType(type);
	}
}
void loadForms() {
	ifstream fin;
	fin.open("forms.txt");
	if (!fin.is_open()) {
		cout << "There was a problem opening the forms text file.";
		exit(1);
	}
	int formIdNum = 0;
	int formPokeId = 0;
	string formName = "";
	for (int i = 0; i < 157; ++i) {
		fin >> formIdNum >> formName >> formPokeId;
		Form temp(formName, formPokeId, formIdNum);
		alternates[i] = temp;
	}
	//forms loaded and placed into array.
	fin.close();
}
void loadFormTypes() {
	ifstream fin;
	int formid;
	string type;
	fin.open("formtypes.txt");
	for (int i = 0; i < 272; ++i) {
		fin >> formid >> type;
		alternates[formid-1].addType(type);
	}
}
void loadFormAbils() {
	ifstream fin;
	int formid = 0; //which form the ability corresponds to. use getPokeId
	int tempid = 0; //ability id
	bool tempBool = true; //hidden or not
	int tempSlot = 0; //which slot the ability is in
	fin.open("formabilities.txt");
	if (!fin.is_open()) {
		cout << "There was an error opening the form abilities file." << endl;
		exit(1);
	}
	//form ID > ability ID > hidden > slot
	for (int i = 0; i < 236; ++i) {

		fin >> formid >> tempid >> tempBool >> tempSlot;
		string nameToAdd = abilities[tempid - 1];
		string descToAdd = abildescs[tempid - 1];
		Ability temp(tempid, tempBool, tempSlot, nameToAdd);
		//pokes[pokeId - 1].addAbility(temp);
		alternates[formid - 1].addAbility(temp);
	}
	fin.close();
}
void loadFormStats() {
	ifstream fin;
	int pokeid = 0;
	int statNum = 0;
	int statVal = 0;
	fin.open("formstats.txt");
	if (!fin.is_open()) {
		cout << "There was an error opening the forms stats database." << endl;
		exit(1);
	}
	for (int i = 0; i < 942; ++i) {
		fin >> pokeid >> statNum >> statVal;
		alternates[pokeid - 1].addStats(statNum, statVal);
	}
}
void addFormsToPokes() {
	for (int i = 0; i < 157; ++i) {
		int temp = alternates[i].getPokeId();
		pokes[temp - 1].addForm(alternates[i]);
	}
}

void displayDescr(string name, string desc) {
	string temp = desc;
	string temp2 = name;
	for (unsigned int i = 0; i < desc.size(); ++i) {
		if (desc[i] == '-') {
			desc[i] = ' ';
		}
		if (desc[i] == '_') {
			desc[i] = '-';
		}
	}
	name[0] = toupper(name[0]);
	for (unsigned int i = 0; i < name.size(); ++i) {
		if (name[i] == '-') {
			name[i] = ' ';
			name[i + 1] = toupper(name[i + 1]);
		}
	}
	
	cout << name << endl << desc;
	desc = temp;
	name = temp2;
}

int main() {
	loadPokemon();
	loadAbilNames();
	loadAbils();
	loadStats();
	loadTypes();
	loadForms();
	loadFormTypes();
	loadFormAbils();
	loadFormStats();
	addFormsToPokes();
	string input;
	cout << "Please enter a Pokemon or Ability name! Enter \"quit\" to quit." << endl;

	do {
		bool thingsWorked = false;
		getline(cin, input);


		for (unsigned int i = 0; i < input.size(); ++i) {
			if (isupper(input[i])) {
				input[i] = tolower(input[i]);
			}
			if (input[i] == ' ') {
				input[i] = '-';
			}
		}
		cout << endl << endl << endl << endl << endl << endl;
		for (int i = 0; i < 807; ++i) {
			if (input == pokes[i].getName()) {
				pokes[i].display();
				cout << endl << endl << "Enter another Pokemon/Ability, or enter \"quit\" to exit.";
				thingsWorked = true;
			}
		}
		for (int i = 0; i < 233; ++i) {
			if (input == abilities[i]) {
				
				displayDescr(abilities[i], abildescs[i]);
				cout << endl << endl << "Enter another Pokemon/Ability, or enter \"quit\" to exit.";
				thingsWorked = true;
			}
		}
		if (!thingsWorked) {
			cout << "Invalid Pokemon or Ability name. Please try again."; 
		}
		cout << endl;
		if (input == "Quit" || input == "quit") {
			break;
		}
	} while (cin);
	return 0;
}