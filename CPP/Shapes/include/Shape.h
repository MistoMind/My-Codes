#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Shape{
    private:
        string name;
        int vertices;
        float length, breath;
        string color;
    
    public:
        Shape();
        void set_name(string name);
        void set_ver(int ver);
        void set_len(float len);
        void set_bre(float bre);
        void set_color(string col);
        string get_name();
        int get_ver();
        float get_len();
        float get_bre();
        string get_color(); 
        Shape get_shape();
};

#endif