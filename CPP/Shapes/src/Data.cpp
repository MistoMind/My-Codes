#include "include/Data.h"
#define SAVEFILE "shapes.data"

Data::Data(){

}

void Data::default_data(){
    ofstream fout;
    fout.open(SAVEFILE);
    fout << "Triangle 3 1 1 Green\n";
    fout << "Circle 0 1 1 Yellow\n";
    fout << "Square 4 1 1 Blue\n";
    fout.close();
}

void Data::create_file(){
    ifstream fin(SAVEFILE);
    if(!fin){
        default_data();
    }
    fin.close();
}

int Data::tot_entries(){
    ifstream fin(SAVEFILE);
    int i = 0;
    string buffer;
    if(fin){
        while(getline(fin, buffer))
            i++;
    }
    fin.close();
    return i;
}

void Data::dis_data(){
    cout << "\nThe Data of the " << shp.get_name() << " is:-" << endl;
    cout << "Number of vertices = " << shp.get_ver() << endl;
    cout << "The length = " << shp.get_len() << endl;
    cout << "The breath = " << shp.get_bre() << endl;
    cout << "The color of the shape = " << shp.get_color() << "\n" << endl;
}

Shape Data::get_data(int line){
    ifstream fp(SAVEFILE);
    string buf;
    char buffer[30];
    float temp;
    for(int i=1;i<line;i++){
        getline(fp, buf);
    }
    fp >> buffer;
    shp.set_name(buffer);
    fp >> temp;
    shp.set_ver(temp);
    fp >> temp;
    shp.set_len(temp);
    fp >> temp;
    shp.set_bre(temp);
    fp >> buffer;
    shp.set_color(buffer);
    
    fp.close();
    return shp;
}

bool Data::entry_err(int num){
    entries = tot_entries();
    if(num>entries || num<=0)
        return true;
    return false;
}

void Data::list_shp_names(){
    ifstream fp(SAVEFILE);
    entries = tot_entries();

    for(int i=1;i<=entries && fp;i++){
        string name;
        fp >> name;
        cout << "(" << i << ") " << name << endl;
        getline(fp, name);
    }

    fp.close();
}

void Data::show_shp_data(int selec){
    if(!entry_err(selec)){
        shp = get_data(selec);
        dis_data();
    }else cout << "Not listed!! Or Data Not present" << endl;
}

void Data::add_entry(){
    fstream fout(SAVEFILE, ios::app);
    string input;
    cout << "Enter name of the shape: ";
    cin >> input;
    fout << input;
    cout << "Enter number of vertices: ";
    cin >> input;
    fout << " " << input;
    cout << "Enter Length of the shape: ";
    cin >> input;
    fout << " " << input;
    cout << "Enter Breath of the shape: ";
    cin >> input;
    fout << " " << input;
    cout << "Enter Color of the shape: ";
    cin >> input;
    fout << " " << input << endl;
    fout.close();
}

void Data::rm_shp(int selec){
    ifstream fin(SAVEFILE);
    ofstream fout("temp.data");

    char c;
    int line = 1;
    while (fin.get(c)){
        if(line != selec)
            fout << c;
        if(c == '\n')
            line++;
    }
  
    fin.close();
    fout.close();
    remove(SAVEFILE);
    rename("temp.data", SAVEFILE);
}

void Data::edit_shp(int shp_line){
    ifstream fin(SAVEFILE);
    ofstream fout("temp.data");

    char c;
    int line = 1;

    shp = get_data(shp_line);
    string buf;

    while(fin.get(c)){
        if(line == shp_line){
            getline(fin, buf);
            fin.get(c);
            line++;
            while(1){
            int selec;
            int ver;
            string name, color;
            float len, bre;
            cout << "Following Data Can be changed:-" << endl;
            cout << "(1) Name" << endl;
            cout << "(2) Number of Vertices" << endl;
            cout << "(3) Length" << endl;
            cout << "(4) Breath" << endl;
            cout << "(5) Color" << endl;
            cout << "(0) Save" << endl;
            cout << "Your Selection: ";
            cin >> selec;

            switch(selec){
                case 1:
                    cout << "Enter new name: ";
                    cin >> name;
                    shp.set_name(name);
                    break;
                case 2:
                    cout << "Enter new number of Vertices: ";
                    cin >> ver;
                    shp.set_ver(ver);
                    break;
                case 3:
                    cout << "Enter new Length: ";
                    cin >> len;
                    shp.set_len(len);
                    break;
                case 4:
                    cout << "Enter new Breath: ";
                    cin >> bre;
                    shp.set_bre(bre);
                    break;
                case 5:
                    cout << "Enter new color: ";
                    cin >> color;
                    shp.set_color(color);
                    break;
                case 0: 
                    cout << "Saving Complete" << endl;
                    break;
            }
            if(!selec){ 
                fout << shp.get_name() << " " << shp.get_ver() << " " << shp.get_len() << " " << shp.get_bre() << " " << shp.get_color() << endl;
                break;
            }
            }
        }

        if(line!=shp_line)
            fout << c;
            
        if(c=='\n')
            line++;
    }
    fin.close();
    fout.close();
    remove(SAVEFILE);
    rename("temp.data", SAVEFILE);
}

void Data::wipe_data(){
    ofstream fout;
    fout.open(SAVEFILE);
    fout << "\0";
    fout.close();
}