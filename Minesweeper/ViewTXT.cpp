#include "ViewTXT.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void ViewTXT::View()
{
	cout << "Pozostalo bomb: " << ile_bomb << endl << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (c_plansza[i][j] == 10)
			{
				SetConsoleTextAttribute(hConsole, 9);
				cout << "o" << " ";
			}
			else if (c_plansza[i][j] == 12)
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << "z" << " ";
			}
			else if (plansza[i][j] == 11)
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "*" << " ";
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 2);
				cout << c_plansza[i][j] << " ";
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void ViewTXT::PlayTxt()
{
	char move;
	int x = 0, y = 0, replay = 0;

	system("cls");

	Init();

	while (true)
	{
		View();
		cout << "Co chcesz zrobic? (o - odslon komorke / z - oflaguj komorke)" << endl;
		cin >> move;
		if (move != 'o' && move != 'z')
		{
			cout << "Podales zla operacje, sproboj ponownie" << endl << endl;
			cout << "Co chcesz zrobic? (o - odslon komorke / z - oflaguj komorke)" << endl;
			cin >> move;
		}
		cout << "Podaj wspolzedna x komorki: " << endl;
		cin >> x;
		cout << "Podaj wspolzedna y komorki: " << endl;
		cin >> y;
		if (x >= a || y >= a)
		{
			cout << "Podales zle wzpolrzedne, sprobuj ponownie" << endl;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
		}
		if (wybierzPole(x, y, move) == false)
		{
			system("cls");
			cout << "Trafiles na mine! Przegrywasz." << endl;
			View();

			cout << "Czy chcesz zagrac ponownie? (0 - nie, 1 - tak)" << endl;
			cin >> replay;
			if (replay == 1) {
				for (int i = 0; i < a; i++)
					for (int j = 0; j < a; j++)
					{
						c_plansza[i][j] = 10;
						plansza[i][j] = 10;
					}
				Init();
				PlayTxt();
			}
			break;
		}
		if (ile_bomb == 0 && oflagowane_puste == 0)
		{
			system("cls");
			cout << "Gratulacje! Wygrales." << endl;
			View();
			cout << "Czy chcesz zagrac ponownie? (0 - nie, 1 - tak)" << endl;
			cin >> replay;
			if (replay == 1) {
				for (int i = 0; i < a; i++)
					for (int j = 0; j < a; j++)
					{
						c_plansza[i][j] = 10;
						plansza[i][j] = 10;
					}
				Init();
				PlayTxt();
			}
			break;
		}
		system("cls");
	}
}

ViewTXT& ViewTXT::operator=(const ViewTXT& v)
{
	return *this;
}
