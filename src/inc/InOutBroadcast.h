#ifndef LINEINOUTBROADCAST
#define LINEINOUTBROADCAST

#include "InOut.h"
#include "Net/Payload.h"
#include "Net/Server.h"


class InOutBroadcast : public InOut {
public:
	InOutBroadcast(InOut *inOut, Server *server)
		: server(server), inOut(inOut) {};
	virtual void announce(string) const override;
	virtual void announceTurn(string, unsigned int turn) const override;
	virtual void renderShips(vector<Ship>) override;
	virtual string ask(string question) const override;

	virtual void askShipLoc(Ship*) const override;
	virtual const Location askShot(const vector<Shot> *shots) const override;
	virtual void renderShotResult(const Shot) const override;
	virtual void gameOver(string player) const override;

private:
	Server* server;
	InOut* inOut;
};

#endif
