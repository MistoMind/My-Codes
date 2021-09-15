#include "Category.h"

Category::Category(){
    name = "";
    entries = 0;
}

void Category::set_name(string n){
    name = n;
}

string Category::get_name(){
    return name;
}

void Category::addTask(){
    Task t = Task();
    string input;

    cout << "\nAdding new Task:-" << endl;
    cout << "Enter description: ";
    getline(cin, input);
    t.set_description(input);
    cout << "Enter date: ";
    getline(cin, input);
    t.set_date(input);
    cout << "Enter time: ";
    getline(cin, input);
    t.set_time(input);
    
    member.push_back(t);
    entries++;
    cout << "Task Added!" << endl;
}

void Category::rmTask(int n){
    if(entries==0){
        cout << "There are zero Task! Cannot Remove" << endl;
    }else if(n>entries){
        cout << "There is no such Task! Cannot Remove" << endl;
    }else {
        member.erase(member.begin()+n-1);
        entries--;
    }
}

void Category::edit(){
    string input;
    int num;
    char selc;

    do{
        cout << "\nFollowing can be edited:-" << endl;
        cout << "(1) Change Name" << endl;
        cout << "(2) Add Task" << endl;
        cout << "(3) Remove Task" << endl;
        cout << "(4) Edit Task" << endl;
        cout << "(5) Rearrange the Tasks" << endl;
        cout << "(6) Display all Tasks" << endl;
        cout << "(c) Clear Screen" << endl;
        cout << "(0) Done Editing" << endl;
        cout << "Your Selection: ";
        cin >> selc;
        getchar();

        if(entries==0 && (selc=='3' || selc=='4' || selc=='5' || selc=='6')){
			cout << "There are no Tasks! Please Add before this operation" << endl;
		}else {
        switch(selc){
            case '0':
                cout << "Category Updated Successfully!" << endl;
                break;
            case '1':
                cout << "Enter new name: ";
                getline(cin, name);
                break;
            case '2':
                addTask();
                break;
            case '3':
                cout << "Enter Task number to remove: ";
                cin >> num;
                rmTask(num);
                break;
            case '4':
                cout << "Enter Task number to edit: ";
                cin >> num;
                if(num<=entries)
                    member[num-1].edit();
                else cout << "There is no such Task! Cannot Edit" << endl;
                break;
            case '5':
                rearrange();
                break;
            case '6':
                displayList();
                break;
            case 'c':
                system("clear");
                break;
            default:
                cout << "Invalid Selection!" << endl;
        }
        }
    }while(selc!='0');
}

void Category::swapTask(Task *t1, Task *t2){
	Task temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

void Category::rearrange(){
    int from, to;
    char selc;

    do{
        displayList();
        cout << "Move task from: ";
        cin >> from;
        cout << "Move task to: ";
        cin >> to;

        if(from>entries || to>entries || from<0 || to<0)
            cout << "Invalid Selection of Task! Cannot move" << endl;
        else {
            swapTask(&member[from-1], &member[to-1]);    
        }

        cout << "Press 0 for done!" << endl;
        cout << "You: ";
        cin >> selc;
    }while(selc!='0');
}

void Category::displayList(){
    cout << endl;
    for(int i=0;i<entries;i++){
        member[i].display(i);
    }
}

void Category::write(ofstream &fout){
    size_t size = name.length();
    fout.write((char *)&size, sizeof(size));
    fout.write(name.c_str(), size);
    size = entries;
    fout.write((char *)&size, sizeof(size));

    for(int i=0;i<member.size();i++)
        member[i].write(fout);
}

void Category::read(ifstream &fin){
    size_t size;
    fin.read((char *)&size, sizeof(size));
    name.resize(size);
    fin.read(&name[0], size);
    fin.read((char *)&size, sizeof(size));
    entries = size;
    if(entries!=0){
        member.reserve(entries);    
    }

    for(int i=0;i<entries;i++)
        member[i].read(fin);
}