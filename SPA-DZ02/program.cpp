#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "game_of_life.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main() {
	game_of_life the_game;
	
	do {
		system("cls");

		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		
		sleep_for(milliseconds(200));
	} while (true);

	return 0;
}