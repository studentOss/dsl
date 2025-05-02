#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node {
    char name[20];
    node *next;
    node *down;
    int flag;
};

class gll {
    char ch[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node *create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node *gll::create() {
    node *p = new node;
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\nEnter the name: ";
    cin >> p->name;
    return p;
}

void gll::insertb() {
    if (head == NULL) {
        t1 = create();
        head = t1;
    } else {
        cout << "\nBook already exists.";
    }
}

void gll::insertc() {
    if (head == NULL) {
        cout << "\nThere is no book.";
    } else {
        cout << "\nHow many chapters do you want to insert? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            t1 = create();
            if (head->flag == 0) {
                head->down = t1;
                head->flag = 1;
            } else {
                temp = head->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void gll::inserts() {
    if (head == NULL) {
        cout << "There is no book.";
        return;
    }
    cout << "\nEnter the chapter name where you want to add a section: ";
    cin >> ch;
    temp = head;
    if (temp->flag == 0) {
        cout << "\nThere are no chapters in the book.";
        return;
    }
    temp = temp->down;
    while (temp != NULL) {
        if (strcmp(ch, temp->name) == 0) {
            cout << "\nHow many sections do you want to enter? ";
            cin >> n;
            for (i = 0; i < n; i++) {
                t1 = create();
                if (temp->flag == 0) {
                    temp->down = t1;
                    temp->flag = 1;
                    t2 = temp->down;
                } else {
                    while (t2->next != NULL) {
                        t2 = t2->next;
                    }
                    t2->next = t1;
                }
            }
            return;
        }
        temp = temp->next;
    }
}

void gll::insertss() {
    if (head == NULL) {
        cout << "\nThere is no book.";
        return;
    }
    cout << "\nEnter the chapter name where you want to add a subsection: ";
    cin >> ch;
    temp = head;
    if (temp->flag == 0) {
        cout << "\nThere are no chapters in the book.";
        return;
    }
    temp = temp->down;
    while (temp != NULL) {
        if (strcmp(ch, temp->name) == 0) {
            cout << "\nEnter the section name where you want to add the subsection: ";
            cin >> ch;
            if (temp->flag == 0) {
                cout << "\nThere are no sections.";
                return;
            }
            temp = temp->down;
            while (temp != NULL) {
                if (strcmp(ch, temp->name) == 0) {
                    cout << "\nHow many subsections do you want to enter? ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        t1 = create();
                        if (temp->flag == 0) {
                            temp->down = t1;
                            temp->flag = 1;
                            t2 = temp->down;
                        } else {
                            while (t2->next != NULL) {
                                t2 = t2->next;
                            }
                            t2->next = t1;
                        }
                    }
                    return;
                }
                temp = temp->next;
            }
        }
        temp = temp->next;
    }
}

void gll::displayb() {
    if (head == NULL) {
        cout << "\nBook does not exist.";
        return;
    }
    temp = head;
    cout << "\nNAME OF BOOK: " << temp->name;
    if (temp->flag == 1) {
        temp = temp->down;
        while (temp != NULL) {
            cout << "\n\tNAME OF CHAPTER: " << temp->name;
            t1 = temp;
            if (t1->flag == 1) {
                t1 = t1->down;
                while (t1 != NULL) {
                    cout << "\n\t\tNAME OF SECTION: " << t1->name;
                    t2 = t1;
                    if (t2->flag == 1) {
                        t2 = t2->down;
                        while (t2 != NULL) {
                            cout << "\n\t\t\tNAME OF SUBSECTION: " << t2->name;
                            t2 = t2->next;
                        }
                    }
                    t1 = t1->next;
                }
            }
            temp = temp->next;
        }
    }
}
int main() {
    gll g;
    int x;
    while (1) {
        cout << "\n\nEnter your choice:";
        cout << "\n1. Insert book";
        cout << "\n2. Insert chapter";
        cout << "\n3. Insert section";
        cout << "\n4. Insert subsection";
        cout << "\n5. Display book";
        cout << "\n6. Exit";
        cout << "\nChoice: ";
        cin >> x;
        switch (x) {
            case 1: g.insertb(); break;
            case 2: g.insertc(); break;
            case 3: g.inserts(); break;
            case 4: g.insertss(); break;
            case 5: g.displayb(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice.";
        }
    }
    return 0;
}
