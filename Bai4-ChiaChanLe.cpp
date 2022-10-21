

#include <iostream>

using namespace std;

// doan 1: dinh nghia node can co chi thay doi kieu du lieu data khi can
typedef struct Node{
	int data;
	Node *Next;
	Node *Prev;// bo sung them so voi dslkdon
}Nodetype;

typedef Nodetype *Nodeptr;

Nodeptr CreateNode(int x){
    Nodeptr p;
	p=new Node;
	p->data=x;
	p->Prev=NULL;
	p->Next=NULL;
	return p;
}

void InsertLast(Nodeptr &Head, Nodeptr &Tail, Nodeptr p){
    if(Head==NULL){
        Head=p;
        Tail=p;
    } else {
        Tail->Next=p;
		p->Prev=Tail;// bo sung them so voi dslkdon
		Tail=p;
    }
}


void Input(int n,int x,Nodeptr &Head, Nodeptr &Tail, Nodeptr p){
    do {
            cout<<"\n Nhap so phan tu n: ";
	        cin>>n;
    }while(n>1000 && n<=0);
   
	
	for(int i=1;i<=n;i++){
	    cout<<"\n nhap gia tri gia tri "<<i<<":";
    	cin>>x;
	    p=CreateNode(x);
	    InsertLast(Head,Tail,p);
	}
}

void Print(Nodeptr Head, Nodeptr Tail){
    Nodeptr p;
    for(Nodeptr p=Head;p!=NULL;p=p->Next){
        cout<<p->data<<"\t";
    }
    
}

void ChiaChanLe(Nodeptr Head, Nodeptr Tail){
    Nodeptr p;
    Nodeptr q,Head2=NULL,Tail2=NULL;
    Nodeptr r,Head3=NULL,Tail3=NULL;
     for(Nodeptr p=Head;p!=NULL;p=p->Next){
         if(p->data%2==0){
             q=CreateNode(p->data);
			 InsertLast(Head2,Tail2,q);
         }else {
             r=CreateNode(p->data);
             InsertLast(Head3,Tail3,r);
         }
     }
     
     cout<<"\nDsLKDOI chan: ";
     Print(Head2,Tail2);
     cout<<"\nDSLKDOI le: ";
     Print(Head3,Tail3);
}

int main(){
    Nodeptr p,Head,Tail;
	Head=Tail=NULL;
	int n;
	int x;
	Input(n,x,Head,Tail,p);
	cout<<"Danh sach lien ket don:\n";
	Print(Head,Tail);
	ChiaChanLe(Head,Tail);
    delete Head;
	delete Tail;
	return 0;
}
