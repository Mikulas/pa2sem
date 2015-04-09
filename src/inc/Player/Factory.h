#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "../InOut.h"
#include "../Net/Server.h"
#include "AI/Random.h"
#include "AI/RandomHunt.h"
#include "AI/RandomWithMemory.h"
#include "Human.h"
#include "Remote.h"

/**
 * Creates instances of Player from string type name
 *
 * \ingroup Player
 */
class PlayerFactory {
public:
	static Player* from(string type, InOut* inOut, Server *server = nullptr) {
		return from(type.c_str(), inOut, server);
	}

	/**
	 * If server is null, silently fails to
	 * create RemotePlayer and returns nullptr
	 *
	 * \returns Player *
	 * \returns `nullptr` on failure
	 */
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

		} else if (strcmp(type, "ai3") == 0) {
			return new RandomHuntAIPlayer();
		}

		return nullptr;
	}
};


#endif
