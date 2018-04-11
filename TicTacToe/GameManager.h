#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "Display.h"

#define SIZE_TAB 5;

class GameManager
{
public:
	void launchGame(char** tab);
	char** loadScore();
	void init(char **tab);
	void saveScore(char** tab);
	bool isFinish(char** tab);
	void isQuit(char** tab);
	std::ostream& saveArray(std::ostream& outfile, char** arr);
	char** loadArray(std::istream& file);
};

#endif