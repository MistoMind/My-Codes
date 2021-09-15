#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "Catalogue.h"

class DataHandler{
private:
	string file;
	ifstream fin;
	ofstream fout;

public:
	DataHandler(string file_name);
	bool file_exists();
	void save(Catalogue &cat);
	Catalogue load();
	void load(Catalogue &cat);
};

#endif