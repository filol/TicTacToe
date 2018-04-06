#include "stdafx.h"
#include "Display.h"
#include <iostream>


using namespace std;

Display::Display()
{
}


Display::~Display()
{
}


void Display::displayInConsole(char tab[5][5], int x, int y) const {
	cout << "SCORE : " << x << " --- " << y << endl << "press -1 for quit or restart "<< endl << endl;
	cout << "---------------------" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		if (i != 0) {
			cout << "|" << endl << "---------------------" << endl;
		}
		for (size_t j = 0; j < 5; j++)
		{
			cout << "| " << tab[i][j] << " ";
		}
	}
	cout << "|" << endl;
	cout << "---------------------" << endl;
}
