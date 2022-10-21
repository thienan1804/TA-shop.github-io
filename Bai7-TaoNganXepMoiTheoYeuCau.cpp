#include<iostream>
#define max 1000

using namespace std;

struct stack{
	int data[max];
	int top;
};

void Push(stack &s, int c){
	if(s.top==max-1)	
	{
		cout<<"\n ngan xep day roi ";
	}
	else
	{
		s.top=s.top+1;
		s.data[s.top]=c;
	}
}

int Pop(stack &s){
	if(s.top==-1)
	{
		//cout<<"\n ngan xep rong";
		return -1;
	}
	else
		{
			return s.data[s.top--];
		}
}

void Input(stack &s, int &n){
	int x;
	do {
	    cout<<"Nhap n: ";
	    cin>>n;    
	    if(n>max || n<1)
	    cout<<"n khong hop le! Vui long nhap lai\n";
	}while(n>max || n<1);
	
	for(int i=0;i<n;i++){
	    cout<<"Nhap phan tu thu "<<i+1<<": ";
	    cin>>x;
	    Push(s,x);
	}
	    
}
void PrintTheoYeuCau(stack s, int n){
	int x;
	int dem=0;
	stack s2;
	s2.top=-1;
	
	cout<<"Ngan xep s1:";
	do{
		x=Pop(s);
		if(x!=-1){
		    cout<<x<<"\t";
		    if(x%2==0 && x>10 && x<20){
		        Push(s2,x);
		    }
		    else {
		        dem++;
		    }  
	    }
	}while(x!=-1);
	
	if(dem==n){
	    cout<<"Khong co gia tri nao thoa yeu cau!\n";
	}
	
	cout<<"Ngan xep s2: ";
    do{
		x=Pop(s2);
		if(x!=-1){
		    cout<<x<<"\t";
	    }
	}while(x!=-1);
}

int main(){

	stack s;
	s.top=-1;
	int n;
	Input(s,n);
	PrintTheoYeuCau(s,n);
	return 0;
}