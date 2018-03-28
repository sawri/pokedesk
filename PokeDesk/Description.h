#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Description {
protected:
	string name;
	string descr;
public:
	Description();
	Description(string nameToAdd, string descrToAdd);
};
#endif