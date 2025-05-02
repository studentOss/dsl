#include <iostream>
#include <cstring>
using namespace std;

class HashFunction {
    typedef struct hash {
        long key;
        char name[100];
    } hash;
    hash h[100];

public:
    HashFunction();
    void insert();
    void display();
    long find(long);
    void Delete(long);
};

HashFunction::HashFunction() {
    for (int i = 0; i < 10; i++) {
        h[i].key = -1;
        strcpy(h[i].name, "NULL");
    }
}

void HashFunction::Delete(long k) {
    int index = find(k);
    if (index == -1) {
        cout << "\n\tKey not found";
    } else {
        h[index].key = -1;
        strcpy(h[index].name, "NULL");
        cout << "\n\tKey is deleted";
    }
}

long HashFunction::find(long k) {
    for (int i = 0; i < 10; i++) {
        if (h[i].key == k) {
            cout << "\n\t" << h[i].key << " is found at " << i << " Location with name " << h[i].name;
            return i;
        }
    }
    return -1;
}

void HashFunction::display() {
    cout << "\n\t\tKey\t\tName";
    for (int i = 0; i < 10; i++) {
        cout << "\n\th[" << i << "]\t" << h[i].key << "\t\t" << h[i].name;
    }
}

void HashFunction::insert() {
    char ans;
    char n[100],ntemp[100];
    long k,temp;
    int hi, cnt = 0, flag = 0,i;

    do {
        if (cnt >= 10) {
            cout << "\n\tHash Table is FULL";
            break;
        }
        cout << "\n\tEnter telephone No: ";
        cin >> k;
        cout << "\n\tEnter client name: ";
        cin >> n;
        hi = k % 10;

        if (h[hi].key == -1) { 
            h[hi].key = k;
            strcpy(h[hi].name, n);
        } 
		else {
		    if (h[i].key%10 !=hi) {
		    	temp=h[hi].key;
		    	strcpy(ntemp,h[hi].name);
		    	h[hi].key=k;
		    	strcpy(h[hi].name,n);
		    	for(i=hi+1;i<10;i++){
		    		if(h[i].key==-1){
		    			h[i].key=temp;
		    			strcpy(h[i].name,ntemp);
		    			flag=1;
		    			break;
					}
				}
				for(i=0;i<hi && flag==0;i++){
					if(h[i].key==-1){
						h[i].key=temp;
						strcpy(h[i].name,ntemp);
						break;
					}
				}	
            }
            else{
            	for(i=hi+1;i<10;i++){
            		if(h[i].key==-1){
            			strcpy(h[i].name,n);
            			flag=1;
            			break;
					}
				}
				for(i=0;i<hi && flag==0;i++){
					if(h[i].key==-1){
						h[i].key=k;
						strcpy(h[i].name,n);
						break;
					}
				}
			}
		}
		flag=0;
		cnt++;
			cout<<"\n___DO you want to insert more key (y/n):";
			cin>>ans;
	}
	while(ans=='y'|| ans=='Y');
}
        
int main() {
    long k;
    int ch, index;
    char ans;
    HashFunction obj;

    do {
        cout << "\n\t**** Dictionary (ADT) ****";
        cout << "\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
        cout << "\n\t...Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "\n\tEnter key which you want to search: ";
            cin >> k;
            index = obj.find(k);
            if (index == -1) {
                cout << "\n\tKey not found";
            }
            break;
        case 4:
            cout << "\n\tEnter key which you want to delete: ";
            cin >> k;
            obj.Delete(k);
            break;
        case 5:
            break;
        default:
            cout << "\n\tInvalid choice!";
        }
        cout << "\n\tDo you want to continue in main menu (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}


