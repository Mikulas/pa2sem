#ifndef INOUT
#define INOUT

class InOut;

#include <string>
#include <Vector>
#include "Board.h"
#include "Location.h"
#include "Ship.h"
#include "Shot.h"
#include "../C.h"

using std::string;
using std::to_string;
using std::vector;


/**
 * Interface for all user communication
 *
 * Implementations might range from console line io, ncurses,
 * network, carry pidgeons and so on.
 *
 * \interface InOut
 * \pure
 */
class InOut
{
    public:
    	virtual ~InOut() {}
        virtual void renderBoard(const Board*) = 0;
        virtual string ask(string question) const = 0;

        virtual void announce(string) const = 0;
        virtual void announceTurn(string, unsigned int turn) const = 0;
        virtual void askShipLoc(Ship*, const Board*) const = 0;
        virtual const Location askShot(const vector<Shot>*) const = 0;
        virtual void renderShotResult(const Shot) const = 0;
        virtual void gameOver(string player) const = 0;
};


#endif
