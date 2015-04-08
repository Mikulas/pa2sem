#ifndef LOCALPLAYER
#define LOCALPLAYER

#include "Player.h"
#include "../InOut.h"
#include "../Random.h"


/**
 * Should only be instantiated client-side or
 * in a local game.
 */
class LocalPlayer : public Player {
public:
    virtual void saveShot(Shot) override;

protected:
	/**
	 * Ships returned should not violate game rules
	 * as failure to do so could saturate bandwith in
	 * networked game (eg if AI would place ships randomly).
	 * If returned ships violate game rules, this
	 * method is invoked again with all ship
	 * locations reset to zero.
	 */
	vector<Ship> placeShipsRandomly(vector<Ship>);

	/**
	 * Stores Player::takeTurn() responses, where
	 * last Shot is at `back()`.
	 */
	vector<Shot> shotsFired;
};

#endif
