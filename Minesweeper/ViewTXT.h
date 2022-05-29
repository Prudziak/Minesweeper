#pragma once
#include "Saper.h"

class ViewTXT : public Saper
{
public:
	int diff;
	ViewTXT(int _diff) : Saper(_diff), diff(_diff) {}
	void PlayTxt();
	virtual void View();

private:
	ViewTXT(const ViewTXT& v);
	ViewTXT& operator=(const ViewTXT& v);
};

