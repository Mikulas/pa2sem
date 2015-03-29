#ifndef LINEINOUT
#define LINEINOUT

#include <exception>
#include <iostream>
#include <map>
#include <stdio.h>
#include "InOut.h"


using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::map;
using std::sscanf;


class LineInOut : public InOut {
public:
	virtual void announce(string) override;
	virtual void announceTurn(string, unsigned int turn) override;
	virtual void renderBoard(Board*) override;
	virtual string ask(string question) override;

	virtual void askShipLoc(Ship*, Board*) override;
	virtual Location askShot(vector<Shot> shots) override;
	virtual void renderShotResult(Shot) override;
	virtual void gameOver(string player) override;

private:
	Location readLocation();
	int symbolHead = 0;
	map<Ship*, string> symbolMap;
	string getCharForShip(Ship*);
	void renderShots(vector<Shot> shots);
};

#endif
