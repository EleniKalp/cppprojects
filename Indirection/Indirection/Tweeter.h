#pragma once
#include "Person.h"

class Tweeter : public Person
{
private: std::string twitterhandle;

public:
	Tweeter(std::string first, std::string last, int arbitrary, std::string hanlde);
	~Tweeter();

	std::string getName() const;
};
