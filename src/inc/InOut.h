#ifndef INOUT
#define INOUT

#include <string>
#include "Board.h"
#include "Location.h"
#include "Ship.h"
#include "Shot.h"
#include "../C.h"

using std::string;


class InOut
{
    public:
    	virtual ~InOut() {}
        virtual void renderBoard(Board*) = 0;
        virtual string ask(string question) = 0;

        virtual void announce(string) = 0;
        virtual void askShipLoc(Ship*, Board*) = 0;
        virtual Location askShot() = 0;
        virtual void renderShotResult(Shot) = 0;
};


#endif
