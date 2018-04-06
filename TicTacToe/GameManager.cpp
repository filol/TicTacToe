#include "stdafx.h"
#include "GameManager.h"
#include <iostream>
#include <string>
#include "Display.h"
#include <stdlib.h>
#include <fstream>


using namespace std;

char playerSign = 'X';
int scoreOfX = 0;
int scoreOfY = 0;

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::launchGame()
{
	bool notFinish = true;
	char tab[5][5] = {};
	Display display;
	int x, y;

	while (notFinish)
	{
		system("cls"); // CLEAR FOR WINDOWS ONLY
		display.displayInConsole(tab, scoreOfX, scoreOfY);
	
		

		cout << "Where to play ? " << endl;
		bool notPossible;
		do {
			x = y = -1;
			while (y < 1 || y>5) {
				cout << "x : ";
				cin >> y;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (y==-1)
				{
					isQuit();
				}
			}
			while (x < 1 || x>5) {
				cout << "y : ";
				cin >> x;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (x == -1)
				{
					isQuit();
				}
			}
			x--; y--;
			notPossible = (tab[x][y] == '/0');
			
		} while (notPossible);
		tab[x][y] = playerSign;
		notFinish = !isFinish(tab);
		playerSign = (playerSign == 'X') ? 'O' : 'X';
	}
	system("cls"); // CLEAR FOR WINDOWS ONLY
	playerSign = (playerSign == 'X') ? 'O' : 'X';
	display.displayInConsole(tab,scoreOfX,scoreOfY);
	cout << "Player " << playerSign << " win !" << endl;
	if (playerSign == 'X')
		scoreOfX++;
	else
		scoreOfY++;
}

bool GameManager::isFinish(char tab[5][5])
{
	//lignes
	for (size_t i = 0; i < 5; i++)
		if (tab[i][0] == playerSign && tab[i][1] == playerSign && tab[i][2] == playerSign && tab[i][3] == playerSign && tab[i][4] == playerSign)
			return true;

	//columns
	for (size_t i = 0; i < 5; i++)
		if (tab[0][i] == playerSign && tab[1][i] == playerSign && tab[2][i] == playerSign && tab[3][i] == playerSign && tab[4][i] == playerSign)
			return true;

	//diags
	if (tab[0][0] == playerSign && tab[1][1] == playerSign && tab[2][2] == playerSign && tab[3][3] == playerSign && tab[4][4] == playerSign)
		return true;
	if (tab[4][0] == playerSign && tab[3][1] == playerSign && tab[2][2] == playerSign && tab[1][3] == playerSign && tab[0][4] == playerSign)
		return true;

	return false;
}

void GameManager::isQuit()
{
	char response;
	cout << "Quit or Restart ? (q or r) " << endl;
	cin >> response;
	if (response == 'q')
	{
		cout << "Save score ? (y or n) " << endl;
		cin >> response;
		if (response == 'y')
		{
			saveScore();
		}
		exit(0);
	}
	else
		launchGame();
}

void GameManager::loadScore()
{
	string line;
	ifstream myfile("score.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);
		scoreOfX = stoi(line);
		getline(myfile, line);
		scoreOfY = stoi(line);
		myfile.close();
	}
}

void GameManager::init()
{
	cout << " Load previous score ? (y or n) " << endl;
	char response;
	cin >> response;
	if (response == 'y')
	{
		loadScore();
	}
}

void GameManager::saveScore()
{
	ofstream myfile;
	myfile.open("score.txt");
	myfile << scoreOfX << "\n" << scoreOfY;
	myfile.close();
}

