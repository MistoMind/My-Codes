#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Task{
private:
	string date;
	string time;
	string description;

public:
	Task();
	void set_date(string d);
	void set_time(string t);
	void set_description(string des);
	string get_date();
	string get_time();
	string get_description();
	void display(int i);
	void edit();
	void write(ofstream &fout);
	void read(ifstream &fin);
};

#endif