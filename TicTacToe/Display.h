#ifndef DISPLAY_H
#define DISPLAY_H


class Display
{
public:
	Display();
	~Display();
	void displayInConsole(char tab[5][5], int x, int y) const;
};

#endif