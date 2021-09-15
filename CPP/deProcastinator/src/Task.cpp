#include "Task.h"

Task::Task(){
	date = "";
	time = "";
	description = "";
}

void Task::set_date(string d){
	date = d;
}

void Task::set_time(string t){
	time = t;
}

void Task::set_description(string des){
	description = des;
}

string Task::get_date(){
	return date;
}

string Task::get_time(){
	return time;
}

string Task::get_description(){
	return description;
}

void Task::display(int i){
	cout << "(" << (i+1) << ") Date: " << date << " || Time: " << time << endl;
    cout << "(" << (i+1) << ") Description: " << description << endl;
    cout << endl;
}

void Task::edit(){
	string input;
	char selc;

    do{
        cout << "\nFollowing can be edited:-" << endl;
        cout << "(1) Description" << endl;
        cout << "(2) Date" << endl;
        cout << "(3) Time" << endl;
        cout << "(0) Done Editing" << endl;
        cout << "Your Selection: ";
		cin >> selc;
		getchar();

        switch(selc){
            case '0':
                cout << "Task Updated Successfully!" << endl;
                break;
            case '1':
                cout << "Type New Description: ";
                getline(cin, description);
                break;
            case '2':
                cout << "Type new Date: ";
                getline(cin, date);
                break;
            case '3':
                cout << "Type new Time: ";
                getline(cin, time);
                break;
            default:
                cout << "Invalid Selection!" << endl;
        }
    }while(selc!='0');
}

void Task::write(ofstream &fout){
	size_t size;
	
	size = date.length();
	fout.write((char *)&size, sizeof(size));
	fout.write(date.c_str(), size);

	size = time.length();
	fout.write((char *)&size, sizeof(size));
	fout.write(time.c_str(), size);

	size = description.length();
	fout.write((char *)&size, sizeof(size));
	fout.write(description.c_str(), size);
}

void Task::read(ifstream &fin){
	size_t size;

	fin.read((char *)&size, sizeof(size));
	date.resize(size);
	fin.read(&date[0], size);

	fin.read((char *)&size, sizeof(size));
	time.resize(size);
	fin.read(&time[0], size);

	fin.read((char *)&size, sizeof(size));
	description.resize(size);
	fin.read(&description[0], size);
}