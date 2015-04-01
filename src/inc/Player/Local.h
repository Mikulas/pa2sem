#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include "Player.h"

class LocalPlayer : public Player
{
    public:
        LocalPlayer(InOut* inOut) : inOut(inOut) {};
    	virtual const Shot respond(const Location) override;
    	virtual bool allShipsSunk() const override;

    protected:
        const Shot fireAt(const Location);
        InOut* inOut;
};

#endif
