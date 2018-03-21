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
	name[0] = toupper(name[0]);
	cout << slot << ". " << name;
	if (hidden) {
		cout << " (Hidden ability)";
	}
	cout << endl;
}