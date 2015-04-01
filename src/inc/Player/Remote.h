#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include "Player.h"
#include "../Net/Server.h"


class RemotePlayer : public Player
{
    public:
        RemotePlayer(Server* server) : server(server) {};
        virtual const Shot respond(const Location) override;
        virtual void setup() override;
        virtual void takeTurn() override;
        virtual bool allShipsSunk() const override;

    private:
    	Server* server;
};


#endif
