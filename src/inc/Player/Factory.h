#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "../InOut.h"
#include "../Net/Server.h"
#include "Human.h"
#include "Remote.h"
#include "AI/Random.h"
#include "AI/RandomWithMemory.h"

class PlayerFactory {
public:
	static Player* from(string type, InOut* inOut, Server *server = nullptr) {
		return from(type.c_str(), inOut, server);
	}

	static Player* from(const char* type, InOut* inOut, Server *server = nullptr) {
		if (strcmp(type, "human") == 0) {
			return new HumanPlayer(inOut);

		} else if (strcmp(type, "net") == 0) {
			if (server == nullptr) {
				return nullptr;
			}
			return new RemotePlayer(server);

		} else if (strcmp(type, "ai1") == 0) {
			return new RandomAIPlayer();

		} else if (strcmp(type, "ai2") == 0) {
			return new RandomWithMemoryAIPlayer();
		}

		return nullptr;
	}
};


#endif
