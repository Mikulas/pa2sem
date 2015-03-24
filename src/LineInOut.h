#ifndef LINEINOUT
#define LINEINOUT

#include <iostream>
#include "InOut.h"


using std::cin;
using std::cout;
using std::endl;
using std::getline;


class LineInOut : public InOut {
public:
	virtual void announce(string) override;
	virtual void renderBoard() override;
	virtual string ask(string question) override;
	virtual Ship askShipLoc(int length, string ship) override;
};


#endif
