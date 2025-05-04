#include <iostream>
#include <fstream>
#include <cstring>  // For strcpy and getline
using namespace std;

class Record {
    int rollno;
    char name[50];       // Fixed-size char array
    int division;
    char address[100];   // Fixed-size char array

public:
    Record();
    int getRollno();
    void getData();
    void putData();
};

Record::Record() {
    rollno = 0;
    strcpy(name, "");
    division = 0;
    strcpy(address, "");
}

int Record::getRollno() {
    return rollno;
}

void Record::getData() {
    cout << "\nEnter Details:";
    cout << "\nRoll No: ";
    cin >> rollno;
    cin.ignore();

    cout << "Name: ";
    cin.getline(name, 50);

    cout << "Division Code: ";
    cin >> division;
    cin.ignore();

    cout << "Address: ";
    cin.getline(address, 100);
}

void Record::putData() {
    cout << "\nRoll No.: " << rollno;
    cout << "\tName: " << name;
    cout << "\nDivision Code: " << division;
    cout << "\tAddress: " << address << "\n";
}

class File {
    ifstream fin;
    ofstream fout;
    fstream fs;

public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};

void File::insert() {
    Record r;
    r.getData();
    fout.open("StudentDB", ios::binary | ios::app);
    fout.write((char*)&r, sizeof(r));
    fout.close();
}

void File::display() {
    Record r;
    fin.open("StudentDB", ios::binary);
    fin.seekg(0, ios::beg);
    while (fin.read((char*)&r, sizeof(r))) {
        r.putData();
    }
    fin.close();
}

void File::search(int rollno) {
    Record r;
    int found = 0;
    fin.open("StudentDB", ios::binary);
    while (fin.read((char*)&r, sizeof(r))) {
        if (r.getRollno() == rollno) {
            cout << "\nRecord Found:";
            r.putData();
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
        cout << "\nRecord not found.";
}

int File::Delete(int rollno) {
    Record r;
    int found = 0;
    fin.open("StudentDB", ios::binary);
    fout.open("Temp", ios::binary);
    while (fin.read((char*)&r, sizeof(r))) {
        if (r.getRollno() == rollno) {
            found = 1;
        } else {
            fout.write((char*)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("StudentDB");
    rename("Temp", "StudentDB");
    return found;
}

int File::edit(int rollno) {
    Record r;
    int found = 0;
    fs.open("StudentDB", ios::binary | ios::in | ios::out);
    while (fs.read((char*)&r, sizeof(r))) {
        if (r.getRollno() == rollno) {
            cout << "\nEnter New Details:";
            r.getData();
            fs.seekp((int)fs.tellg() - sizeof(r));
            fs.write((char*)&r, sizeof(r));
            found = 1;
            break;
        }
    }
    fs.close();
    return found;
}

int main() {
    File f;
    int choice, n, flag = 0;

    do {
        cout << "\n\n\t----- MENU -----";
        cout << "\n1. Build Master Table";
        cout << "\n2. Display Records";
        cout << "\n3. Insert New Record";
        cout << "\n4. Delete Record";
        cout << "\n5. Edit Record";
        cout << "\n6. Search Record";
        cout << "\n7. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!flag) {
                cout << "\nEnter number of records to insert: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    f.insert();
                }
                flag = 1;
            } else {
                cout << "\nTable already built. Use option 3 to insert new records.";
            }
            break;
        case 2:
            f.display();
            break;
        case 3:
            f.insert();
            break;
        case 4:
            cout << "\nEnter Roll No to delete: ";
            cin >> n;
            if (f.Delete(n))
                cout << "\nRecord deleted successfully.";
            else
                cout << "\nRecord not found.";
            break;
        case 5:
            cout << "\nEnter Roll No to edit: ";
            cin >> n;
            if (f.edit(n))
                cout << "\nRecord updated successfully.";
            else
                cout << "\nRecord not found.";
            break;
        case 6:
            cout << "\nEnter Roll No to search: ";
            cin >> n;
            f.search(n);
            break;
        case 7:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid choice.";
        }
    } while (choice != 7);

    return 0;
}
