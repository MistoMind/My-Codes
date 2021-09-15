#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "Category.h"

class Catalogue{
private:
	vector<Category> data;
	int entries;

public:
	Catalogue();
	int get_entries();
	void set_entries(int ent);
	void displayList();
	void addCategory();
	void rmCategory(int n);
	void edit();
	void write(ofstream &fout);
	void read(ifstream &fin);
};

#endif