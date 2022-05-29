#pragma once
#include <iostream>
using namespace std;

class Engine
{
public:
	int diff = 0, a = 0;
	int ile_bomb = 0;
	int** plansza;
	int** c_plansza;
	Engine(int _diff);
	virtual ~Engine() {}
public:
	void Init();
	bool isMine(int x, int y);
	void ileBomb(int x, int y);
	void odslonPuste(int x, int y);

private:
	Engine(const Engine& e);
	Engine& operator=(const Engine& e);
};

