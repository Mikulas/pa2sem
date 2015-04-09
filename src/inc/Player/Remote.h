#ifndef PLAYER_REMOTE_H
#define PLAYER_REMOTE_H

class RemotePlayer;

#include "Player.h"
#include "../Net/Server.h"


/**
 * Invokes methods on LocalPlayer through Server connection,
 * making Game completely independent on networking.
 *
 * Should only be instantiated server-side.
 *
 * While RemotePlayer could in theory invoke methods on
 * another instance of RemotePlayer, this is not supported
 * feature and should not be used.
 *
 * \ingroup Player
 */
class RemotePlayer : public Player {
public:
	/**
	 * Server must have socket for this player before
	 * any method is invoked. Results in undefined
	 * behaviour otherwise.
	 */
	RemotePlayer(Server *server) : server(server) {};
	/**
	 * \throws ServerException
	 */
	virtual vector<Ship> setup(vector<Ship>) override;
	/**
	 * \throws ServerException
	 */
	virtual Location takeTurn() override;
	/**
	 * \throws ServerException
	 */
	virtual void saveShot(Shot) override;
private:
	Server* server;
};


#endif
