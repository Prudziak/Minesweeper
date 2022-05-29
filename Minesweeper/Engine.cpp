#include "Engine.h"
#include <iostream>
#include <ctime>

using namespace std;

Engine::Engine(int _diff)
{
	diff = _diff;
	switch (diff) {
	case 1:
		a = 9;
		plansza = new int* [a];
		c_plansza = new int* [a];
		for (int i = 0; i < a; i++)
		{
			plansza[i] = new int[a];
			c_plansza[i] = new int[a];
		}
		for (int i = 0; i < a; i++)
			for (int j = 0; j < a; j++)
			{
				plansza[i][j] = 10;
				c_plansza[i][j] = 10;
			}
		break;
	case 2:
		a = 12;
		plansza = new int* [a];
		c_plansza = new int* [a];
		for (int i = 0; i < a; i++)
		{
			plansza[i] = new int[a];
			c_plansza[i] = new int[a];
		}
		for (int i = 0; i < a; i++)
			for (int j = 0; j < a; j++)
			{
				plansza[i][j] = 10;
				c_plansza[i][j] = 10;
			}
		break;
	case 3:
		a = 15;
		plansza = new int* [a];
		c_plansza = new int* [a];
		for (int i = 0; i < a; i++)
		{
			plansza[i] = new int[a];
			c_plansza[i] = new int[a];
		}
		for (int i = 0; i < a; i++)
			for (int j = 0; j < a; j++)
			{
				plansza[i][j] = 10;
				c_plansza[i][j] = 10;
			}
		break;
	}
}

void Engine::Init()
{
	int x = 0, y = 0, i = 0;
	srand(time(0));
	switch (diff)
	{
	case 1:
		do
		{
			x = rand() % 9, y = rand() % 9;
			plansza[x][y] = 11;
			i++;
		} while (i != 3);
		ile_bomb = i;
		break;
	case 2:
		do
		{
			x = rand() % 12, y = rand() % 12;
			plansza[x][y] = 11;
			i++;
		} while (i != 40);
		ile_bomb = i;
		break;
	case 3:
		do
		{
			x = rand() % 15, y = rand() % 15;
			plansza[x][y] = 11;
			i++;
		} while (i != 85);
		ile_bomb = i;
		break;
	}
}

bool Engine::isMine(int x, int y)
{
	if (plansza[x][y] == 11)
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (plansza[i][j] == 11)
					c_plansza[i][j] = 11;
			}
		}
		return true;
	}
	return false;
}

void Engine::ileBomb(int x, int y)
{
	int ile = 0;

	if (x - 1 < 0 || y - 1 < 0)
		ile += 0;
	else
		if (plansza[x - 1][y - 1] == 11) ile += 1;
	if (x - 1 < 0)
		ile += 0;
	else
		if (plansza[x - 1][y] == 11) ile += 1;
	if (x - 1 < 0 || y + 1 >= a)
		ile += 0;
	else
		if (plansza[x - 1][y + 1] == 11) ile += 1;
	if (y - 1 < 0)
		ile += 0;
	else 
		if (plansza[x][y - 1] == 11) ile += 1;
	if (y + 1 >= a)
		ile += 0;
	else
		if (plansza[x][y + 1] == 11) ile += 1;
	if (x + 1 >= a || y - 1 < 0)
		ile += 0;
	else 
		if (plansza[x + 1][y - 1] == 11) ile += 1;
	if (x + 1 >= a)
		ile += 0;
	else 
		if (plansza[x + 1][y] == 11) ile += 1;
	if (x + 1 >= a || y + 1 >= a)
		ile += 0;
	else
		if (plansza[x + 1][y + 1] == 11) ile += 1;
	
	c_plansza[x][y] = ile;

}

void Engine::odslonPuste(int x, int y)
{
	if (x < 0 || x >= a) return;
	if (y < 0 || y >= a) return;

	if (c_plansza[x][y] < 10 || c_plansza[x][y] == 12) return;

	ileBomb(x, y);
	if (c_plansza[x][y] == 0)
	{
		odslonPuste(x, y - 1);
		odslonPuste(x, y + 1);
		odslonPuste(x - 1, y);
		odslonPuste(x + 1, y);
	}
}

Engine& Engine::operator=(const Engine& e)
{
	return *this;
}
