#ifndef PLAYER
#define PLAYER

class Player;

#include <vector>
#include "../Location.h"
#include "../Ship.h"
#include "../Shot.h"

using std::vector;


/**
 * \interface Player
 * \pure
 */
class Player {
public:
	/**
	 * Called by game loop for until all ships
	 * are placed according to rules.
	 * Implementations may enforce any rules at
	 * this point.
	 */
    virtual vector<Ship> setup(vector<Ship>) = 0;
    /**
     * Asks player at which field he or she wants
     * to shoot at.
     * Response is asynchronous to make networked
     * implementations easier.
     * \ see saveShot
     */
	virtual Location takeTurn() = 0;
	/**
	 * Called after takeTurn() returns with shot result.
	 * Is inteded for-but not limited to-AI implementaions.
	 * Called with Shot with location of last valid takeTurn.
	 * Should not output to user, shot results are handled by Game.
	 */
	virtual void saveShot(Shot) = 0;
};

#endif
