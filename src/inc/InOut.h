#ifndef INOUT_H
#define INOUT_H

class InOut;

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "../C.h"
#include "Board.h"
#include "Location.h"
#include "Ship.h"
#include "Shot.h"

using std::cerr;
using std::endl;
using std::runtime_error;
using std::string;
using std::to_string;
using std::vector;


/**
 * Interface for all user communication
 *
 * Implementations might range from console line IO,
 * ncurses to carry pidgeons and so on.
 *
 * \interface InOut
 * \pure
 */
class InOut {
public:
	virtual ~InOut() {}
    /**
     * Shows Ship locations on board
     */
    virtual void renderShips(vector<Ship>) = 0;
    /**
     * Prompts user for input
     * \warning Does not enforce any format
     *
     * Expected usage:
     * \code{.cpp}
     * while (true) {
     *    string answer = inOut->ask("You ok? [Y/n]: ");
     *    if (answer ...) { // answer in valid format
     *        // do something with response
     *        break;
     *    }
     *    // otherwise prompt again
     * }
     * \endcode
     */
    virtual string ask(string question) const = 0;
    /**
     * Print generic game state change, for
     * example used to announce which player
     * setup is taking place
     */
    virtual void announce(string) const = 0;
    virtual void announceTurn(string, unsigned int turn) const = 0;
    /**
     * Prompt user for new Ship coordinates
     * and save it directly to the instance.
     * Should validate game rules (ship length)
     * to improve user experience, but on failure
     * to do so, this method is invoked again.
     *
     * \see Player::setup()
     */
    virtual void askShipLoc(Ship*) const = 0;
    /**
     * \see Player::takeTurn()
     */
    virtual const Location askShot(const vector<Shot>*) const = 0;
    /**
     * Invoked by Game after Player::takeTurn()
     */
    virtual void renderShotResult(const Shot) const = 0;
    /**
     * Invoked by Game after Player::takeTurn() if
     * last shot sunk last opponents boat.
     */
    virtual void gameOver(string player) const = 0;

    void renderError(runtime_error &e) {
        cerr << C::red << "Sorry, game over: " << e.what() << C::reset << endl;
    }
    void renderError(string msg) {
        cerr << C::red << msg << C::reset << endl;
    }
};


#endif
