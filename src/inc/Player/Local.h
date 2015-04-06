#ifndef LOCALPLAYER
#define LOCALPLAYER

#include "Player.h"
#include "../InOut.h"


class LocalPlayer : public Player {
    public:
        LocalPlayer(InOut* inOut) : inOut(inOut) {};
        virtual void saveShot(Shot) override;

	protected:
    	vector<Shot> shotsFired;
        InOut* inOut;
};

#endif
