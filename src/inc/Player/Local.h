#ifndef LOCALPLAYER
#define LOCALPLAYER

#include "Player.h"
#include "../InOut.h"
#include "../Random.h"


class LocalPlayer : public Player {
    public:
        virtual void saveShot(Shot) override;

	protected:
		vector<Ship> placeShipsRandomly(vector<Ship>);

    	vector<Shot> shotsFired;
};

#endif
