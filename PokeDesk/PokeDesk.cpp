#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "pokemon.h"
#include "Ability.h"
#include "Form.h"
using namespace std;
Pokemon pokes[807]; //array of all pokemon
string abilities[233]; //array of abilities
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
	fin.open("abilitynames.txt");
	if (!fin.is_open()) {
		cout << "There was an error opening the ability names file." << endl;
		exit(1);
	}
	for (int i = 0; i < 233; ++i) {
		fin >> counter >> tempname;
		abilities[i] = tempname;
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
	for (int i = 0; i < 1931; ++i) {

		fin >> formid >> tempid >> tempBool >> tempSlot;
		string nameToAdd = abilities[tempid - 1];
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

int main() {
	loadPokemon();
	loadAbilNames();
	loadAbils();
	loadStats();
	loadForms();
	loadFormAbils();
	loadFormStats();
	addFormsToPokes();
	//Ability test(44, 0, 1, "Chicken");
	//pokes[45].alternates[0].addAbility(test);
	string input;
	do {
		cout << "Please enter a pokemon name! Enter \"quit\" to quit." << endl;
		cin >> input;
		cout << endl << endl << endl << endl << endl << endl;
		for (int i = 0; i < 807; ++i) {
			if (input == pokes[i].getName()) {
				pokes[i].display();
			}
		}
		cout << endl;
		if (input == "Quit" || input == "quit") {
			break;
		}
	} while (cin);
	return 0;
}