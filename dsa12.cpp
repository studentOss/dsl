#include <iostream>
#include <fstream>
#include <cstring>
#include <map> // ADD THIS FOR INDEX
using namespace std;

class Record {
    int id;
    char name[50];
    int salary;
    char designation[50];

public:
    Record();
    int getIdno();
    void getData();
    void putData();
};

Record::Record() {
    id = 0;
    strcpy(name, "");
    salary = 0;
    strcpy(designation, "");
}

int Record::getIdno() {
    return id;
}

void Record::getData() {
    cout << "\nEnter Details: ";
    cout << "\nId no: ";
    cin >> id;
    cin.ignore();

    cout << "Name: ";
    cin.getline(name, 50);

    cout << "Salary: ";
    cin >> salary;
    cin.ignore();

    cout << "Designation: ";
    cin.getline(designation, 50);
}

void Record::putData() {
    cout << "\nId No.: " << id;
    cout << "\t\tName: " << name;
    cout << "\nSalary: " << salary;
    cout << "\tDesignation: " << designation;
}
class File {
    ifstream fin;
    ofstream fout;
    fstream fs;
    map<int, streampos> index; // INDEX MAP
public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
    void buildIndex(); // BUILD INDEX FUNCTION
};
void File::buildIndex() {
    index.clear();
    Record r;
    fin.open("EmployeeDB", ios::binary);
    while (fin.read((char*)&r, sizeof(r))) {
        streampos pos = fin.tellg();
        index[r.getIdno()] = pos - sizeof(r);
    }
    fin.close();
}
void File::insert() {
    Record r;
    r.getData();
    fout.open("EmployeeDB", ios::binary | ios::app);
    fout.write((char *)&r, sizeof(r));
    fout.close();
}
void File::display() {
    Record r;
    fin.open("EmployeeDB", ios::binary);
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r)))
        r.putData();
    fin.close();
}
void File::search(int id) {
    buildIndex();
    Record r;
    //if (index.find(id) != index.end()) {
    if(index.contains(id){
        fin.open("EmployeeDB", ios::binary);
        fin.seekg(index[id]);
        fin.read((char*)&r, sizeof(r));
        cout << "\nRecord Found:";
        r.putData();
        fin.close();
    } else {
        cout << "\nRecord not Found ";
    }
}
int File::Delete(int id) {
    Record r;
    int flag = 0;
    fin.open("EmployeeDB", ios::binary);
    fout.open("Temp", ios::binary | ios::app);
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
        } else {
            fout.write((char *)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("EmployeeDB");
    rename("Temp", "EmployeeDB");
    return flag;
}

int File::edit(int id) {
    buildIndex();
    Record r;
    int flag = 0;
    if (index.find(id) != index.end()) {
        fs.open("EmployeeDB", ios::binary | ios::in | ios::out);
        fs.seekg(index[id]);
        fs.read((char*)&r, sizeof(r));
        cout << "\nEnter New Details: ";
        r.getData();
        fs.seekp(index[id]);
        fs.write((char*)&r, sizeof(r));
        fs.close();
        flag = 1;
    }
    return flag;
}

int main() {
    File f;
    int ch, n, i, flag = 0;
    do {
        cout << "\n\n\t-----M E N U-----";
        cout << "\n\n1. Build A Master Table";
        cout << "\n2. List A Table";
        cout << "\n3. Insert a New Entry";
        cout << "\n4. Delete Old Entry";
        cout << "\n5. Edit an Entry";
        cout << "\n6. Search for a Record";
        cout << "\n7. Quit";
        cout << "\nEnter your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            if (flag == 0) {
                cout << "\nEnter No of Records to insert : ";
                cin >> n;
                for (i = 0; i < n; i++) {
                    f.insert();
                }
                flag = 1;
            } else {
                cout << "\nSorry.. Table is Already built...\nIf you want to add a record, please select Insert a New Entry from the menu.";
            }
            break;
        case 2:
            f.display();
            break;
        case 3:
            f.insert();
            break;
        case 4:
            cout << "\nEnter Id No of Employee Whose Record is to be Deleted: ";
            cin >> n;
            i = f.Delete(n);
            if (i == 1)
                cout << "\nRecord Deleted Successfully";
            else
                cout << "\nRecord not Found";
            break;
        case 5:
            cout << "\nEnter Id No of Employee Whose Record is to be Edited: ";
            cin >> n;
            i = f.edit(n);
            if (i == 1)
                cout << "\nRecord Modified Successfully";
            else
                cout << "\nRecord not Found";
            break;
        case 6:
            cout << "\nEnter Id No of Employee Whose Record is to be Searched: ";
            cin >> n;
            f.search(n);
            break;
        case 7:
            break;
        default:
            cout << "\nEnter Valid Choice.....";
        }
    } while (ch != 7);
    return 0;
}
