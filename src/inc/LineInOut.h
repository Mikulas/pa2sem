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
	virtual void announce(string) const override;
	virtual void announceTurn(string, unsigned int turn) const override;
	virtual void renderShips(vector<Ship>) override;
	virtual string ask(string question) const override;

	virtual void askShipLoc(Ship*) const override;
	virtual const Location askShot(const vector<Shot> *shots) const override;
	virtual void renderShotResult(const Shot) const override;
	virtual void gameOver(string player) const override;

private:
	const Location readLocation() const;
	int symbolHead = 0;
	map<const Ship*, string> symbolMap;
	string getCharForShip(const Ship*);
	void renderShots(const vector<Shot> *shots) const;
	Ship* isShipAt(vector<Ship> *ships, Location) const;
};

#endif
