#ifndef LOCALPLAYER
#define LOCALPLAYER

#include "Player.h"
#include "../InOut.h"


class LocalPlayer : public Player {
    public:
        virtual void saveShot(Shot) override;

	protected:
    	vector<Shot> shotsFired;
};

#endif
