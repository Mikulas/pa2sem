#ifndef INOUT
#define INOUT

#include <string>
#include "Location.h"
#include "Ship.h"

using std::string;


class InOut
{
    public:
    	virtual ~InOut() {}
        virtual void renderBoard() = 0;
        virtual string ask(string question) = 0;

        virtual Ship askShipLoc(int length, string ship) = 0;
};


#endif
