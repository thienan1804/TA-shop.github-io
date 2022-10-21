#include<iostream>
#include<iomanip>
#define max 1000
using namespace std;

struct Queue
{
	int Head,Tail;
	int Data[max];
};

void PushQ(Queue &q,int x)
{
	int vt;
	vt=(q.Tail+1)%max;
	if(vt==q.Head){
		cout<<"\n Hàng đợi đầy";
		//exit(0);
	}
	else{
		q.Data[vt]=x;
		q.Tail=vt;
	}
}

int IsEmpty(Queue &q){
	return (q.Head==q.Tail?1:0);
}

int PopQ(Queue &q){
	
	int vt;
	int iteam;
	while(!IsEmpty(q)){
		vt=(q.Head+1)%max;
		iteam=q.Data[vt];
		q.Head=vt;
		return iteam;
	}
	return -1;
}

void input(Queue &q, int &n){
	int x;
	do{
	    cout<<"Nhap n: ";
	    cin>>n;    
	    if(n>max || n<1)
	    cout<<"n khong hop le! Vui long nhap lai\n";
	}while(n>max || n<1);
	
	for(int i=0;i<n;i++){
	    cout<<"Nhap phan tu thu "<<i+1<<": ";
	    cin>>x;
	    PushQ(q,x);
	}
}

bool KiemTraSoHoanHao(int shh){
    int sum=0;
    for(int i=1;i<shh;i++){
        if(shh%i==0)sum=sum+i;
    }
    return sum==shh?true:false;
}

void Print(Queue q, int n){
    	int x,dem=0,sohoanhao[n];
    	for(int i=0;i<n;i++){
        	x=PopQ(q);
		if(KiemTraSoHoanHao(x)){
		    dem++;
		}
    	}
	cout<<"Co tat ca "<<dem<<" so hoan hao trong hang doi!";
}


int main(){
	//khai bao hang doi
	Queue q;
	//khoi tao hang doi rong
	q.Head=q.Tail=0;
	int n;
	input(q,n);
	Print(q,n);
	return 0;
}