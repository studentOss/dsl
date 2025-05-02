#include<iostream>
#include<cstring>
using namespace std;
class hf{
	typedef struct hash{
		int key;
		int val;
	}hash;
	hash h[100];
	public:
		hf();
		void insert();
		void Delete(int);
		int find(int);
		void display();
};
hf::hf(){
	for(int i=0;i<10;i++){
		h[i].key=-1;
		h[i].val=-1;
	}
}
void hf::display(){
	cout<<"\n\tkey\t\tvalue";
	for(int i=0;i<10;i++){
		cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].val;
	}
}
void hf::Delete(int k){
	int idx=find(k);
	if(idx==-1){
		cout<<"\n key is not found";
	}
	else{
		h[idx].key=-1;
		h[idx].val=-1;
		cout<<"\nkey deleted ";
	}
}
int hf::find(int k){
	for(int i=0;i<10;i++){
		if(h[i].key==k){
			cout<<"\nkey is found"<<h[i].key<<" with val"<<h[i].val;
		    return i;
		}
	}
	return -1;
}
void hf::insert(){
	char ans;
	int v;
	int hi,cnt=0,flag=0;
	int k;
	do{
		if(cnt>=10){
			cout<<"\ntable is full";
		}
		cout<<"\nEnter the key:";
		cin>>k;
		cout<<"\nEnter the value:";
		cin>>v;
		hi=k%10;
		if(h[hi].key==-1){
			h[hi].key=k;
			h[hi].val=v;
		}
		else{
			for(int i=hi+1;i<10;i++){
				if(h[i].key==-1){
					h[i].key=k;
					h[i].val=v;
					flag=1;
					break;
				}
			}
			if(flag==0){
			for(int i=0;i<hi;i++){
				if(h[i].key==-1){
					h[i].key=k;
					h[i].val=v;
					break;
				}
			}
		}
		}
		cnt++;
		flag=0;
		cout<<"\nDo u want to insert more key's (y/n):";
		cin>>ans;
	}
	while(ans=='y' || ans=='Y');
}
int main(){
	char ans;
	int k;
	int v;
	int c;
	int idx;
	hf obj;
	do{
		cout<<"\n****Dict(ADT)****";
		cout<<"\n\t1.insert\n\t2.delete\n\t3.display\n\t4.find\n\t5.exit";
       	cout<<"\n\tEnter ur choice:";
     	cin>>c;
	    switch(c){
	    	case 1:
	    		obj.insert();
	    		break;
	    	case 2:
	    		cout<<"\nEnter the key to be deleted:";
	    		cin>>k;
	    		obj.Delete(k);
	    		break;
	    	case 3:
	    		obj.display();
	    		break;
	    	case 4:
	    		cout<<"\nEnter the key to be search:";
	    		cin>>k;
	    	    idx=obj.find(k);
	    		if(idx==-1){
	    			cout<<"\nkey not found";
				}
				break;
			case 5:
				break;
			default:
				cout<<"\npls enter valid choice";
		}
		cout<<"\nDo u want to continue in main menu(Y/N):";
		cin>>ans;
	}
	while(ans=='y'|| ans=='Y');
	return 0;
}

