#include "include/Engine.h"

Engine::Engine(Map &land){
	win = lost = false;
	map = &land;
}

Engine::~Engine(){
	// Nothing till now!
}

bool Engine::complete(){
	if(win==true || lost==true)
		return true;
	else return false;
}

int getch(){
	struct termios oldattr, newattr;
	int ch;
	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return ch;
}

int kbhit(){
	static const int STDIN = 0;
	static bool initialized = false;

	if(!initialized){
		termios term;
		tcgetattr(STDIN, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN, TCSANOW, &term);
		setbuf(stdin, NULL);
		initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN, FIONREAD, &bytesWaiting);
	return bytesWaiting;
}


char Engine::user_input(){
	float time_limit = 0.5;
	time_t start = time(NULL);
	fflush(0);
	while(!kbhit()){
		if((time(NULL)-start) >= time_limit){
			return -1;
		}
	}
	return getch();
}

void Engine::collision_result(){
	int obj = map->get_id(map->to_x, map->to_y);

	if(obj==0){
		map->place(1, map->to_x, map->to_y);
		map->place(0, map->cur_x, map->cur_y);
		map->cur_x = map->to_x;
		map->cur_y = map->to_y;
	}

	if(obj==2){
		map->to_x = map->cur_x;
		map->to_y = map->cur_y;
	}

	if(obj==3){
		win = true;
		map->place(100, map->to_x, map->to_y);
		map->place(0, map->cur_x, map->cur_y);
	}

	if(obj==4){
		if(map->get_hp()>10){
			map->damage(10);
			map->place(1, map->to_x, map->to_y);
			map->place(0, map->cur_x, map->cur_y);
			map->cur_x = map->to_x;
			map->cur_y = map->to_y;
		}else {
			lost = true;
			map->place(99, map->to_x, map->to_y);
			map->place(0, map->cur_x, map->cur_y);
		}
	}

	if(obj==5){
		map->damage(100);
		lost = true;
		map->place(99, map->to_x, map->to_y);
		map->place(0, map->cur_x, map->cur_y);
	}	
}

void Engine::move_ene(){
	float time_limit = 0.5;
	time_t start = time(NULL);
	if((time(NULL)-start) >= time_limit){
	int x = map->ene_x_loca;
	int y = map->ene_y_loca;

	switch(map->ene_dir){
		case 'u':
			map->ene_y_loca--;
			break;
		case 'd':
			map->ene_y_loca++;
			break;
	}
	map->place(5, map->ene_x_loca, map->ene_y_loca);
	map->place(0, x, y);

	if(map->ene_y_loca+1==map->get_size()-1){
		map->ene_dir = 'u';
	}
	if(map->ene_y_loca-1==0){
		map->ene_dir = 'd';
	}
	}
}

void Engine::process_frame(){
	char move = user_input();
	int temp;
	switch(move){
		case 'w':
			map->to_y--;
			break;
		case 's':
			map->to_y++;
			break;
		case 'a':
			map->to_x--;
			break;
		case 'd':
			map->to_x++;
			break;
	}

	collision_result();
	move_ene();
}