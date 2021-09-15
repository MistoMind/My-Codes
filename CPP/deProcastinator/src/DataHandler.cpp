#include "DataHandler.h"

DataHandler::DataHandler(string file_name){
    file = file_name;
}

bool DataHandler::file_exists(){
    fin.open(file);
    if(fin.is_open()){
        fin.close();
        return true;
    }
    return false;
}

void DataHandler::save(Catalogue &cat){
    fout.open(file, ios::out | ios::binary);

    size_t size = cat.get_entries();
    fout.write((char *)&size, sizeof(size));
    cat.write(fout);

    fout.close();
}

void DataHandler::load(Catalogue &cat){
    fin.open(file, ios::in | ios::binary);

    size_t size;
    fin.read((char *)&size, sizeof(size));
    cat.set_entries(size);
    cat.read(fin);

    fin.close();
}