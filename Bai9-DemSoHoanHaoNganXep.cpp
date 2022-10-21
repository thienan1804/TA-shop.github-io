#include<iostream>
#define max 1000

using namespace std;

struct stack{
	int data[max];
	int top;
};

void Push(stack &s, int c){
    if(s.top==max){
        cout<<"Ngan xep day roi!";
    }
    else{
        s.top=s.top+1;
	    s.data[s.top]=c;
    }

}

int Pop(stack &s){
	if(s.top==0){
		return -1;
	}
	else{
		return s.data[s.top--];
	}
}

void Input(stack &s, int &n){
	int x;
	do {
	    cout<<"Nhap n: ";
	    cin>>n;    
	    if(n<1)
	    cout<<"n khong hop le! Vui long nhap lai\n";
	}while(n<1);
	
	for(int i=0;i<n;i++){
	    cout<<"Nhap phan tu thu "<<i+1<<": ";
	    cin>>x;
	    Push(s,x);
	}
	    
}

bool KiemTraSoHoanHao(int shh){
    int sum=0;
    for(int i=1;i<shh;i++){
        if(shh%i==0)sum=sum+i;
    }
    return sum==shh?true:false;
}

void Print(stack s, int n){
    	int x,dem=0,sohoanhao[n];
    	for(int i=0;i<n;i++){
        	x=Pop(s);
		if(KiemTraSoHoanHao(x)){
		    dem++;
		}
    }
	cout<<"Co tat ca "<<dem<<" so hoan hao trong ngan xep!";
}

int main(){
	stack s;
	s.top=0;
	int n;
	Input(s,n);
	Print(s,n);
	return 0;
}