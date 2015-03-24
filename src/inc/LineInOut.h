#ifndef LINEINOUT
#define LINEINOUT

#include <exception>
#include <iostream>
#include <stdio.h>
#include "InOut.h"


using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::sscanf;


class LineInOut : public InOut {
public:
	virtual void announce(string) override;
	virtual void renderBoard() override;
	virtual string ask(string question) override;

	virtual void askShipLoc(Ship*) override;
	virtual Location askShot() override;

private:
	Location readLocation();
};


#endif
