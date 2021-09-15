#include <stdlib.h>
#include <ctime>
#include "include/Map.h"
#include "include/Display.h"
#include "include/Engine.h"

int main(){
    srand(time(0));
    Map map = Map(20);
    Engine game = Engine(map);
    Display show = Display();
    show.controls();
    char ch = game.user_input();
    int frame = 0;
    do{
    	map.render();
    	game.process_frame();
	}while(!game.complete());
    map.render();
}