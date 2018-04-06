#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H



class GameManager
{
public:
	GameManager();
	~GameManager();
	void launchGame();
	void loadScore();
	void saveScore();
	bool isFinish(char tab[5][5]);
};

#endif