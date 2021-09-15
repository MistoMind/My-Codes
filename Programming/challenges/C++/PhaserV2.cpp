#include <bits/stdc++.h>
using namespace std;

#define ENDSTR buffer.length()-1

struct Tag{
	string name;
	map<string, string> attribute;
	int cur_pos=0;
	vector<Tag> subtag;
	Tag *parent_addr;

	Tag* subAddr(){
		return &subtag[subtag.size()-1];
	}
};

int main(){
	ifstream fin("Phaser_Input.txt");
	Tag main_tag;
	main_tag.name = "Main Tag";
	Tag *ptr = &main_tag;
	int source, query;
	string buffer;

	fin >> source >> query;
	// cin >> source >> query;

	for(int i=1;i<=source;i++){
		Tag temp;
		string key, value;

		// cin >> buffer;
		fin >> buffer;

		if(buffer[1]!='/'){
			if(buffer[ENDSTR]!='>'){
				temp.name = buffer.substr(1, ENDSTR);

				while(1){
					// cin >> buffer;
					fin >> buffer;

					key = buffer;

					// cin >> buffer >> buffer;
					fin >> buffer >> buffer;

					if(buffer[ENDSTR]=='>'){
						value = buffer.substr(1, ENDSTR-2);
						break;
					}else value = buffer.substr(1, ENDSTR-1);
					temp.attribute.insert({key, value});
				}
			}else{
				temp.name = buffer.substr(1, ENDSTR-1);
			}
		}else{
			ptr = ptr->parent_addr;
		}

		temp.parent_addr = ptr;
		ptr->subtag.push_back(temp);
		ptr = ptr->subAddr();
	}

	cout << "Showing the data saved: " << endl;
	ptr = &main_tag;

	cout << "ptr name = " << ptr->name << endl;
	for(int i=0;i<main_tag.subtag.size();i++){
		main_tag.cur_pos = i;
		cout << "ptr name = " << ptr->name << endl;
	}

	for(int i=1;i<=query;i++){

	}

	fin.close();
}