#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include "Shape.h"
using namespace std;

class Data{
   private:
	   Shape shp = Shape();
	   int entries;

	public:
	   Data();
       void default_data();
	   void create_file();
	   int tot_entries();
       void dis_data();
       Shape get_data(int line);
       bool entry_err(int num);
       void list_shp_names();
       void show_shp_data(int selec);
       void add_entry();
       void rm_shp(int selec);
       void edit_shp(int selec);
       void wipe_data();
};

#endif