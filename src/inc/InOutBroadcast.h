#ifndef INOUTBROADCAST_H
#define INOUTBROADCAST_H

#include "InOut.h"
#include "Net/Payload.h"
#include "Net/Server.h"


/**
 * Composite pattern for InOut
 *
 * Relays all calls to original InOut and
 * also broadcasts to all users connected to
 * Server when appropriate.
 */
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
