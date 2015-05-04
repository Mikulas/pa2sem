#include "RandomHunt.h"

RandomHuntAIPlayer::RandomHuntAIPlayer() {
	for (unsigned int x = 0; x < BOARD_SIZE; x++) {
		for (unsigned int y = 0; y < BOARD_SIZE; y++) {
			shootAt.push_back(new Location(x, y));
		}
	}
	auto engine = default_random_engine{};
	shuffle(std::begin(shootAt), std::end(shootAt), engine);
}

vector<Ship> RandomHuntAIPlayer::setup(vector<Ship> ships) {
	return placeShipsRandomly(ships);
}

void RandomHuntAIPlayer::addHunted(unsigned int x, unsigned int y) {
	try {
		Location loc(x, y);

		auto i = std::begin(shootAt);
		while (i != std::end(shootAt)) {
		    if (loc == **i) {
		    	hunted.insert(*i);
		    	shootAt.erase(i);
		    	break;
		    }
		    ++i;
		}

	} catch (InvalidLocationException &e) {
		// ignore
	}
}

void RandomHuntAIPlayer::addHunted(Location &loc) {
	addHunted(loc.x, loc.y - 1);
	addHunted(loc.x, loc.y + 1);
	addHunted(loc.x - 1, loc.y);
	addHunted(loc.x + 1, loc.y);
}

Location RandomHuntAIPlayer::takeTurn() {
	if (shotsFired.size() > 0) {
		Shot lastShot = shotsFired.back();
		if (lastShot.response != Shot::Response::MISS) {
			addHunted(lastShot.location);
		}
	}

	if (hunted.size() > 0) {
		Location loc = **hunted.begin();
		delete *hunted.begin();
		hunted.erase(hunted.begin());
		return loc;
	}

	// random search
	Location loc = *shootAt.back();
	delete shootAt.back();
	shootAt.pop_back();
	return loc;
}
