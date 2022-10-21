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
	if(vt==q.Head)
	{
		cout<<"\n Queue Full";
		//exit(0);
	}
	else
	{
		q.Data[vt]=x;
		q.Tail=vt;
	}
}

int IsEmpty(Queue &q)
{
	return (q.Head==q.Tail?1:0);
}
int PopQ(Queue &q)
{
	
	int vt;
	int iteam;
	while(!IsEmpty(q))
	{
		vt=(q.Head+1)%max;
		iteam=q.Data[vt];
		q.Head=vt;
		return iteam;
	}
	return -1;
}
void input(Queue &q, int &n)
{
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
void Print(Queue q, int n)
{
	int x,dem=0;
	Queue q2;
	q2.Head=q2.Tail=0;

    cout<<"Gia tri duoc luu tru trong hang doi s1:\t";
	do {
	     x=PopQ(q);
	     if(x!=-1){
	         cout<<x<<"\t";
	         if(x%2==0 && x>10 && x<20){
	             PushQ(q2,x);
	         }
	         else{
	             dem++;
	         }
	         
	     }
	}while (x!=-1);

	if(dem==n){
	    cout<<"Khong co gia tri nao thoa yeu cau!\n";
	}
	
	cout<<"\nGia tri duoc luu tru trong hang doi s2:\t";
	do {
	     x=PopQ(q2);
	     if(x!=-1){
	         cout<<x<<"\t";
	     }
	}while (x!=-1);
}
int main()
{
	//khai bao hang doi
	Queue q;
	//khoi tao hang doi rong
	q.Head=q.Tail=0;
	int n;
	input(q,n);
	Print(q,n);
	return 0;
}