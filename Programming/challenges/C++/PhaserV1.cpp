#include <bits/stdc++.h>
using namespace std;

#define ENDSTR buffer.length()-1

class Tag{
	public:
		string name;
		vector<string> attribute;
		vector<string> value;
};

bool isAttribute(string buffer){
	char c = buffer[0];
	if(c!='<' && c!='=' && c!='\"' && c!='>')
		return true;
	else return false;
}

int main(){
	// cout << "Compiled successfully " << endl;
	int source, query;
	ifstream fin("Phaser_Input.txt");
	// cin >> source >> query;
	fin >> source >> query;

	vector<Tag> tags;
	string buffer;

	// Reading the input for source
	// cout << "Reading and saving the data" << endl;
	for(int i=1;i<=source;i++){
		Tag temp;
		// cin >> buffer;
		fin >> buffer;
		if(buffer[1]!='/'){
			// Get the name
			if(buffer[ENDSTR]!='>'){
				temp.name = buffer.substr(1, ENDSTR);

				// Get the attributes and their values until > not found
				while(1){
					// cin >> buffer;
					fin >> buffer;

					temp.attribute.push_back(buffer);
					// cin >> buffer >> buffer;
					fin >> buffer >> buffer;

					if(buffer[ENDSTR]=='>'){
						temp.value.push_back(buffer.substr(1, ENDSTR-2));
						break;
					}else temp.value.push_back(buffer.substr(1, ENDSTR-1));
				}
			}else {
				temp.name = buffer.substr(1, ENDSTR-1);
			}

			tags.push_back(temp);
		}
	}

	// cout << "\n\nShowing saved data!!" << endl;
	// for(int i=0;i<tags.size();i++){
		// cout << "Name = " << tags[i].name << endl;
		// for(int j=0;j<tags[i].attribute.size();j++){
			// cout << "Attribute = " << tags[i].attribute[j] << endl;
			// cout << "Value = " << tags[i].value[j] << endl;
		// }
		// cout << endl;
	// }
	// cout << endl;

	// Querying now
	// cout << "\n\nReading queries and printing results" << endl;
	for(int i=0;i<query;i++){
		bool check = true;
		int tag_num=0, att_num=0;
		int pos=0;
		string temp;

		// cout << "\nReading buffer" << endl;
		// cin >> buffer;
		fin >> buffer;
		buffer += "\n";
		// cout << "New query-----------------------------------" << endl;
		// cout << "buffer = " << buffer << endl;
		while(check){
			temp.clear();
			while(buffer[pos]!='~' && buffer[pos]!='.'){
				temp.push_back(buffer[pos]);
				pos++;
			}

			// cout << "Temp = " << temp << endl;

			// cout << "Checking ." << endl;
			if(buffer[pos]=='.'){
				// cout << "Temp is holding tag name" << endl;
				if(tag_num>=tags.size() && temp!=tags[tag_num].name){
					// cout << "Tag name doesn't exist" << endl;
					check = false;
					break;
				}
				tag_num++;
				// cout << "Found similar tag name " << endl;
				pos++;
				continue;
			}

			// cout << "Checking ~" << endl;
			if(buffer[pos]=='~'){
				if(tag_num>=tags.size() && temp!=tags[tag_num].name){
					// cout << "Tag name doesn't exist" << endl;
					check = false;
					break;
				}
				// cout << "Temp is holding attribute" << endl;
				temp.clear();
				while(buffer[++pos]!='\n')
					temp.push_back(buffer[pos]);
				for(int j=0;j<tags[tag_num].attribute.size();j++){
					check = false;
                    if(tags[tag_num].attribute[att_num]==temp){
                        check = true;
                        break;
                    }
                    att_num++;
				}
				break;
			}
		}

		// cout << "\nThe value of this is ";
		if(check){
			cout << tags[tag_num].value[att_num] << endl;
		}else cout << "Not Found!" << endl;
		// cout << endl;
		// cout << "Done query----------------------------------" << endl;
	}

	// fin.close();
}