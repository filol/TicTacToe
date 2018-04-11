#include "stdafx.h"
#include "GameManager.h"


using namespace std;

char playerSign = 'X';
int scoreOfX = 0;
int scoreOfY = 0;

void GameManager::launchGame(char** tab)
{
	bool notFinish = true;
	const int size = 5;
	/*if (tab == nullptr) {
		tab = new char*[size];
		for (int i = 0; i < size; ++i) {
			tab[i] = new char[size];
			for (int j = 0; j < size; j++) {
				tab[i][j] = ' ';
			}
		}
	}*/

	

	
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
					isQuit(tab);
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
					isQuit(tab);
				}
			}
			x--; y--;
			notPossible = *(*(tab+x)+y) == '/0';
			
		} while (notPossible);
		*(*(tab+x)+y) = playerSign;
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

bool GameManager::isFinish(char** tab)
{	
	int size = SIZE_TAB;
	//lignes
	for (size_t i = 0; i < 5; i++)
		for (size_t j = 0; j<size; j++)
			if (*(*(tab+i)+j) == playerSign)

	//columns
	for (size_t i = 0; i < 5; i++)
		for (size_t j =0;j<size;j++)
			if (*(*(tab + i) + j) == playerSign)
				return true;

	//diags
	for (size_t j = 0; j<size; j++)
		if (*(*(tab + j) + j) == playerSign)
			return true;
	
	int i = size;
	int j = 0;
	while (i < size) {
		if (*(*(tab + i) + j) == playerSign)
			return true;
		i--; j++;
	}

	return false;
}

void GameManager::isQuit(char** tab)
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
			saveScore(tab);
		}
		exit(0);
	}
	else
		launchGame(nullptr);
}

char** GameManager::loadScore()
{
	ifstream myfile("score.txt", ios::out);
	return loadArray(myfile);
}

void GameManager::init(char** tab)
{
	cout << " Load previous score ? (y or n) " << endl;
	char response;
	cin >> response;
	if (response == 'y')
	{
		tab = loadScore();
	}
}

void GameManager::saveScore(char** tab)
{
	ofstream of("score.txt");
	saveArray(of,tab);
}



ostream& GameManager::saveArray(ostream& outfile, char** arr) {
	const int size = SIZE_TAB;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			char value = arr[i][j] == ' ' ? '0' : arr[i][j];
			outfile << value << " ";
		}
	return outfile;
}

char ** GameManager::loadArray(istream &file)
{
	const int size = SIZE_TAB;;
	char** arr = new char*[size];
	for (int i = 0; i < size; i++) {
		arr[i] = new char[size];
		for (int j = 0; j < size; j++) {
			file >> arr[i][j];
			if (arr[i][j] == '0') 
				arr[i][j] = ' ';
		}
		return arr;
	}
}
	

