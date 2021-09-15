#include <iostream>
#include <cstring>
#include "include/DataHandler.h"
#define DATA "user_data"
using namespace std;

int main(int argc, char *argv[]){
    system("clear");
	DataHandler io = DataHandler(DATA);
    Catalogue main_data = Catalogue();
    char selc;

    if(io.file_exists()){
        io.load(main_data);
    }

    if(argc==2 && !strcmp(argv[1], "l")){
        cout << "List Mode Selected!" << endl;
        main_data.displayList();
    }else {
        do{
            cout << "\nFollowing Options are available:-" << endl;
            cout << "(1) Display Everything" << endl;
            cout << "(2) Edit Mode" << endl;
            cout << "(c) Clear Screen" << endl;
            cout << "(e) Erase all Data" << endl;
            cout << "(s) Save" << endl;
            cout << "(0) Save & Exit" << endl;
            cout << "Your Selection: ";
            cin >> selc;
            getchar();

            switch(selc){
                case '0':
                    io.save(main_data);
                    cout << "Saving and Exiting" << endl;
                    break;
                case 's':
                    io.save(main_data);
                    cout << "Save Complete" << endl;
                    break;
                case '1':
                    main_data.displayList();
                    break;
                case '2':
                    main_data.edit();
                    break;
                case 'c':
                    system("clear");
                    break;
                case 'e':
                    remove(DATA);
                    break;
                default:  
                    cout << "Invalid Selection!" << endl;
            }
        }while(selc!='0');
    }
}