#include "stdafx.h"
#include "Ability.h"

using namespace std;

Ability::Ability() {
	name = "";
	id = 0;
	hidden = true;
	slot = 0;
}

Ability::Ability(int idNum, bool isHidden, int slotNum, string abName) {
	id = idNum;
	hidden = isHidden;
	slot = slotNum;
	name = abName;
}

void Ability::addName(string abName) {
	name = abName;
}

void Ability::display() {
	string temp = name;
	name[0] = toupper(name[0]);
	for (unsigned int i = 0; i < name.size(); ++i) {
		if (name[i] == '-') {
			name[i] = ' ';
			name[i + 1] = toupper(name[i + 1]);
		}
	}
	cout << slot << ". " << name;
	if (hidden) {
		cout << " (HA)";
	}
	cout << endl;
	name = temp;
}