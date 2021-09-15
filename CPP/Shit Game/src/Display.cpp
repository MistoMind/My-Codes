#include "include/Display.h"

Display::Display(){
    cout << "\t\t\"Welcome to the Game\"\n";
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~~\n\n";
}

void Display::controls(){
    cout << endl;
    cout << "\t\t>Use \"w\" to move up\n";
    cout << "\t\t>Use \"s\" to move down\n";
    cout << "\t\t>Use \"a\" to move left\n";
    cout << "\t\t>Use \"d\" to move right\n";
}