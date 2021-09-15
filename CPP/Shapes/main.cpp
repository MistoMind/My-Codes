#include <iostream>
#include <fstream>
#include "include/Shape.h"
#include "include/Data.h"
#define SAVEFILE "shapes.data"
using namespace std;

int login(){
    char selec;
    string passin, pass = "idontknowthepassword";
    cout << "Login as:-" << endl;
    cout << "(1)User" << endl;
    cout << "(2)Owner" << endl;
    cout << "Your Selection: ";
    fflush(stdin);
    cin >> selec;

    switch(selec){
        case '1':
            return 0;
            break;
        case '2':
            fflush(stdin);
            cout << "Enter password: ";
            cin >> passin;
            if(passin==pass){
                return 1;
            }else {
                cout << "Wrong Password!\n" << endl;
                return login();
            }
            break;
        default:
            cout << "Not listed!! Try again" << endl;
            return login();
            break;
    }
    return 0;
}

/*
    Okay I know this could have been really better but come on
*/

int main(){
    Shape shp = Shape();
    Data io = Data();
    int user = login();

    if(user==0){
        io.create_file();
        cout << "\nThere are below shapes:-" << endl;
        io.list_shp_names();
        cout << "(0) Quit" << endl;
        while(1){
            int selec;
            cout << "Enter number to get data of the shape: ";
            cin >> selec;
            if(!selec) break;
            io.show_shp_data(selec);
        }
    }else if(user==1){
        io.create_file();
        while(1){
        int in;
        cout << "--------------------------------------" << endl;
        cout << "Operations on data:-" << endl;
        cout << "(1) View all names" << endl;
        cout << "(2) View data of a shape" << endl;
        cout << "(3) Add a new shape" << endl;
        cout << "(4) Remove a shape" << endl;
        cout << "(5) Edit data of a shape" << endl;
        cout << "(6) View all Shapes with data" << endl;
        cout << "(7) Wipe all data" << endl;
        cout << "(8) Reset data to defaults" << endl;
        cout << "(0) Quit" << endl;
        cout << "Your Selection: ";
        cin >> in;
        cout << "--------------------------------------" << endl;
        cout << endl;

        if(!in) break;

        switch(in){
            case 1:
                io.list_shp_names();
                cout << endl;
                break;
            case 2:
                int selec;
                cout << "Enter the shape number: ";
                cin >> selec;
                io.show_shp_data(selec);
                break;
            case 3:
                io.add_entry();
                break;
            case 4:
                cout << "Enter the shape number: ";
                cin >> selec;
                if(!io.entry_err(selec))
                    io.rm_shp(selec);
                else cout << "Not a valid entry!!" << endl;
                break;
            case 5:
                cout << "Enter the shape number: ";
                cin >> selec;
                if(!io.entry_err(selec))
                    io.edit_shp(selec);
                else cout << "Not a valid entry!!" << endl;
                break;
            case 6:
                for(int i=1;i<=io.tot_entries();i++)
                    io.show_shp_data(i);
                break;
            case 7:
                io.wipe_data();
                break;
            case 8:
                io.default_data();
                break;
            default:
                cout << "Not listed option!!" << endl;
        }
        }
    }

    cout << "Thank You! For using our service!!" << endl;
}