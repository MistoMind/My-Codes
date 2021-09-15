#include "include/Map.h"
#define MAX_TRAP size*2

Map::Map(int size){
    this->size = size;
    map = (int **)malloc(size*sizeof(int *));
    for(int i=0;i<size;i++)
        map[i] = (int *)malloc(size*sizeof(int));

    for(int r=0;r<size;r++)
        for(int c=0;c<size;c++){
            if(r==0 || c==0 || r==size-1 || c==size-1)
                map[r][c] = 2;
            else map[r][c] = 0;
        }
    int x,y;
    bool check = true;
    while(check){
        x = rand()%2;
        y = rand()%2;
        if(x==0)
            y = rand()%(size-1);
        else if(y==0)
            x = rand()%(size-1);
        else if(x==1)
            x = size-1;
        else if(y==1)
            y = size-1;
        else if(x==1 && y==1)
            continue;
        check = false;
    }
    
    map[y][x] = 3;

    for(int i=0;i<MAX_TRAP;i++)
        place_rand(4);
    place_rand(1);
    x = y = 5;
    ene_x_loca = x;
    ene_y_loca = y;
    map[ene_y_loca][ene_x_loca] = 5;
    ene_dir = 'u';
}

void Map::place(int id, int x, int y){
    map[y][x] = id;
}

void Map::place_rand(int id){
    int x,y;
    do{
    x = rand()%(size-1);
    y = rand()%(size-1);
    }while(x==0 || y==0 || x==size-1 || y==size-1);
    map[y][x] = id;
    if(id == 1){
        cur_x = to_x = x;
        cur_y = to_y = y;
    }
}

void Map::render(){
    system("clear");
    cout << "\n\n";
    cout << "\t\t\tHero's Health = " << get_hp() << "\n\n";
    for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
            show(map[r][c]);       
        }
        cout << endl;
    }
}

void Map::show(int id){
    for(int i=0;i<MAX_OBJS;i++){
        if(game_obj[i].id==id){
            id = i;
            break;
        }
    }
    cout << game_obj[id].color << game_obj[id].shape << " ";
}