// TicTacToe.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "GameManager.h"

int main()
{
	GameManager gameManager;
	char** tab = nullptr;
	gameManager.init(tab);
	Display display;
	display.displayInConsole(tab,5,5);
	//gameManager.launchGame(tab);

    return 0;
}

