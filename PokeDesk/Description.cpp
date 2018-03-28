#include "stdafx.h"
#include "Description.h"

using namespace std;

Description::Description() {
	name = "";
	descr = "";
}

Description::Description(string nameToAdd, string descrToAdd) {
	name = nameToAdd;
	descr = descrToAdd;
}