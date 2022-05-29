#pragma once
#include "Engine.h"

class Saper : public Engine
{
public:
	int oflagowane_puste, oflagowane_bomby;
	Saper(int _diff) : Engine(_diff) {}
	virtual ~Saper() {}
	bool wybierzPole(int x, int y, char move);
	virtual void View() = 0;

private:
	Saper(const Saper& s);
	Saper& operator=(const Saper& s);
};

