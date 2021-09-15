#ifndef CATEGORY_H
#define CATEGORY_H

#include <vector>
#include "Task.h"

class Category{
private:
	string name;
	int entries = 0;
	vector<Task> member;

public:
	Category();
	void set_name(string n);
	string get_name();
	void addTask();
	void rmTask(int n);
	void edit();
	void swapTask(Task *t1, Task *t2);
	void rearrange();
	void displayList();
	void write(ofstream &fout);
	void read(ifstream &fin);
};

#endif