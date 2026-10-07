#include "Person.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;

string Person::getName() const
{
	return firstname + " " + lastname;
}

Person::Person(string first, string last, int arbitrary):
			firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
				cout << "constructing " << firstname << " " << lastname << '\n';
}

Person::~Person()
{

}