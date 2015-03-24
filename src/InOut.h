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

        virtual void announce(string) = 0;
        virtual Ship askShipLoc(int length, string ship) = 0;
        virtual Location askShot() = 0;

    protected:
        const string reset = "\033[0m";
		const string underline = "\033[4m";
    	const string red = "\033[31m";
		const string green = "\033[32m";
		const string blue = "\033[34m";
};


#endif
