#ifndef MAP_H
#define MAP_H

#include <malloc.h>
#include <iostream>
#define MAX_OBJS 9
using namespace std;

class Map{
    private:
        int **map;
        int size;

        struct obj{
    		int id;
    		char shape;
    		string color;
    	}game_obj[MAX_OBJS] = {
    		{0, ' ', ""},
    		{1, 'H', "\e[34m"},
    		{2, '#', "\e[33m"},
    		{3, 'T', "\e[32m"},
            {4, 'X', "\e[31m"},
            {5, 'l', "\e[36m"},
            {6, '-', "\e[36m"},
            {99, 'O', "\e[35m"},
            {100, '$', "\e[93m"}
		};

        int hero_health = 100;

    public:
        int cur_x, cur_y, to_x, to_y;
        int ene_x_loca, ene_y_loca;
        char ene_dir;
        Map(int size);
        void place(int id, int x, int y);
        void place_rand(int id);
        int get_size(){return size;};
        void render();
        void show(int id);
        int get_id(int x, int y){return map[y][x];};
        int get_hp(){return hero_health;};
        void damage(int x){hero_health-=x;};
};

#endif