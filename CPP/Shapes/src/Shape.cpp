#include "include/Shape.h"

Shape::Shape(){
    vertices = length = breath = 0;
}

void Shape::set_name(string name){
    this->name = name;
}

void Shape::set_ver(int ver){
    vertices = ver;
}

void Shape::set_len(float len){
    length = len;
}

void Shape::set_bre(float bre){
    breath = bre;
}

void Shape::set_color(string col){
    color = col;
}

string Shape::get_name(){
    return name;
}

int Shape::get_ver(){
    return vertices;
}

float Shape::get_len(){
    return length;
}

float Shape::get_bre(){
    return breath;
}

string Shape::get_color(){
    return color;
}

Shape Shape::get_shape(){
    return *this;
}