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
	virtual void renderBoard(Board*) override;
	virtual string ask(string question) override;

	virtual void askShipLoc(Ship*, Board*) override;
	virtual Location askShot() override;
	virtual void renderShotResult(Shot) override;

private:
	Location readLocation();
	map<Ship*, string> symbolMap;
	string getCharForShip(Ship*);
};

#endif
