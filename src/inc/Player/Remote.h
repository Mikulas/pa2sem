#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include "Player.h"
#include "../Net/Server.h"


class RemotePlayer : public Player
{
    public:
        RemotePlayer(InOut* inOut, Server* server)
        	: Player(inOut), server(server) {};
        virtual void setup() override;
        virtual void takeTurn() override;

    private:
    	Server* server;
};


#endif
