#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// ABCDEFGHIJKLMNOPQRSTUVWXYZ

char toNum(char in){
	if(!isalpha(in))
		return in;
	in = tolower(in);
	string num = "48C037GH11K13N096R574VWXY2";
	return num[in-'a'];
}

char toSym(char in){
	if(!isalpha(in))
		return in;
	in = tolower(in);
	string sym = "@bcdefg#!j%lm~op@r$tu^wxyz";
	return sym[in-'a'];
}

string gpass(string input){
	int selc, prev=0;

	for(int i=0;i<input.length();i++){
		do{
			selc = rand()%4;
		}while(selc==prev);
		prev = selc;

		switch(selc){
			case 0:
				input[i] = toupper(input[i]);
				break;
			case 1:
				input[i] = tolower(input[i]);
				break;
			case 2: 
				input[i] = toNum(input[i]);
				break;
			case 3:
				input[i] = toSym(input[i]);
				break;
		}
	}

	return input;
}

int main(){
	srand(time(0));
	string input;
	cout << "Enter your password to strong it: ";
	cin >> input;
	cout << gpass(input) << endl;
}