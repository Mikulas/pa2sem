#ifndef REMOTEPLAYER
#define REMOTEPLAYER

#include "Player.h"


class RemotePlayer : public Player
{
public:
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;
	virtual void saveShot(Shot) override;
};


#endif
