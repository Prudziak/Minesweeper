#include "Saper.h"
#include <iostream>

using namespace std;

bool Saper::wybierzPole(int x, int y, char move)
{
	switch (move)
	{
	case 'o':
		if (isMine(x, y))
			return false;
		else
		{
			if (c_plansza[x][y] == 12)
				ile_bomb++;
			//ileBomb(x, y);
			odslonPuste(x, y);
			return true;
		}
		break;
	case 'z':
		if (c_plansza[x][y] == 12)
		{
			ile_bomb++;
			c_plansza[x][y] = 10;
			return true;
		}
		else
		{
			if (c_plansza[x][y] < 10)
				return true;
			else if (plansza[x][y] != 11)
			{
				oflagowane_puste++;
				c_plansza[x][y] = 12;
				ile_bomb--;
			}
			else
			{
				c_plansza[x][y] = 12;
				ile_bomb--;
				return true;
			}
		}
		break;
	}
}

Saper& Saper::operator=(const Saper& s)
{
	return *this;
}
