#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include "Map.h"
#include "Display.h"

using namespace std;

class Engine{
	private:
		bool win, lost;
		Map *map;

	public:
		Engine(Map &land);
		~Engine();
		bool complete();
		char user_input();
		void process_frame();
		void collision_result();
		void move_ene();
};

#endif