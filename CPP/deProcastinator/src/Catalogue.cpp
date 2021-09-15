#include "Catalogue.h"

Catalogue::Catalogue(){
	entries = 0;
}

int Catalogue::get_entries(){
	return entries;
}

void Catalogue::set_entries(int ent){
	entries = ent;
}

void Catalogue::displayList(){
	cout << endl;
	for(int i=0;i<entries;i++){
		cout << "======: " << data[i].get_name() << " :======" << endl;
		data[i].displayList();
	}
}

void Catalogue::addCategory(){
	Category cat = Category();
	string input;

	cout << "Adding new Category:-" << endl;
	cout << "Enter name for this category: ";
	getline(cin, input);
	cat.set_name(input);
	while(1){
		cout << "Do you want to add new task(y/n): ";
		getline(cin, input);
		if(input=="n")
			break;
		cat.addTask();
	}
	
	data.push_back(cat);
	entries++;
	cout << "Category Added!" << endl;
}

void Catalogue::rmCategory(int n){
	if(entries==0){
		cout << "There are zero Categories! Cannot Remove" << endl;
	}else if(n>entries){
		cout << "There is no such Category! Cannot Remove" << endl;
	}else {
		data.erase(data.begin()+n-1);
		entries--;
	}
}

void Catalogue::edit(){
	string input;
	int num;
	char selc;

	do{
		cout << "\nFollowing can be edited:-" << endl;
		cout << "(1) Add Category" << endl;
		cout << "(2) Remove Category" << endl;
		cout << "(3) Edit Category" << endl;
		cout << "(4) Display all Categories" << endl;
		cout << "(c) Clear Screen" << endl;
		cout << "(0) Done Editing" << endl;
		cout << "Your Selection: ";
		cin >> selc;
		getchar();

		if(entries==0 && (selc=='2' || selc=='3' || selc=='4')){
			cout << "There are no Categories! Please Add before this operation" << endl;
		}else {
		switch(selc){
			case '0':
				cout << "Updated Successfully!" << endl;
				break;
			case '1':
				addCategory();
				break;
			case '2':
				cout << "Enter Category number to remove: ";
				cin >> num;
				rmCategory(num);
				break;
			case '3':
				cout << "Enter Category number to edit: ";
				cin >> num;
				if(num<=entries)
					data[num-1].edit();
				else cout << "There is no such Category! Cannot Edit" << endl;
				break;
			case '4':
				displayList();
				break;
			case 'c':
                system("clear");
                break;
			default:
				cout << "Invalid Selection!" << endl;
		}
		}
	}while(selc!='0');
}

void Catalogue::write(ofstream &fout){
	for(int i=0;i<entries;i++){
		data[i].write(fout);
	}
}

void Catalogue::read(ifstream &fin){
	data.reserve(entries);
	for(int i=0;i<entries;i++){
		data[i].read(fin);
	}
}