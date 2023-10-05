#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int menu(){
	int i;
	cout<<"          menu"<<endl;
	cout<<"     1. 輸入兩個整數，執行交換動作，並列印結果"<<endl;
	cout<<"     2. 輸入兩個整數，執行相乘動作，並列印結果"<<endl;
	cout<<"     3. 輸入兩個整數，執行比較動作，並列印較大之值"<<endl;
	cout<<"     4. 進行骰子遊戲"<<endl; 
	cout<<"     0. 離開系統"<<endl;
	cout<<"  Please select your choice  ";
	cin>>i;
	return i;
}
//1
int change(int &x,int &y){
	int t;
	t=x;
	x=y;
	y=t;
}
//2
int times(int a,int b){
	int c;
	c=a*b;
	return c;
}
//3
int max(int a,int b){
	int result;
	if(a>b){
		result=a;
	}
	else{
		result=b;
	}
	return result;
}
//4
int choose1(){
		int a;
		cin>>a;
		return a;
	}
int main() {
	int s,k,a,b;
	while(s=menu()){
		switch(s){
			case 1:{
				cout<<"請輸入兩個整數:";
				cin>>a>>b;
				change(a,b);
				cout<<a<<' '<<b<<endl;
				break;
			}
			case 2:{
				cout<<"請輸入兩個整數:";
				cin>>a>>b;
				cout<<"兩數相乘為"<<times(a,b);
				cout<<endl;
				break;
			}
			case 3:{
				cout<<"請輸入兩個整數:";
				cin>>a>>b;
				cout<<"較大的數為"<<max(a,b);
				cout<<endl;
				break;
			}    
			case 4:{
				int a,b=0,x=0,y=0;
				for(b=0;b<5;b++){
					cout<<"請選擇(1)比大或(2)比小:";
					switch(a=choose1()){
					case 1:{
						int computer,you;
						srand(time(NULL));
						computer=(rand()%6)+1;
						you=(rand()%6)+1;
						if(you<computer){
							cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you loss~"<<endl;
							y=y+1;
						}
						if(you>computer){
							cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you win!"<<endl;
							x=x+1;
						}
						if(you==computer){
							cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"The same!"<<endl;
						}
						break;
					}
					case 2:{
						int computer,you;
						srand(time(NULL));
						computer=(rand()%6)+1;
						you=(rand()%6)+1;
						if(you<computer){
							cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you win!~"<<endl;
							x=x+1;
						}
						if(you>computer){
							cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you loss"<<endl;
							y=y+1;
						}
						if(you==computer){
							cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"The same!"<<endl;
						}
						break;
						} 
					} 
				}
				cout<<"你贏"<<x<<"次，"<<"輸"<<y<<"次";
				break;
			}
		default:
			cout<<"輸入錯誤，請重新輸入!!!"  <<endl;     
		} 
	}
	cout<<"Thanks for using, bye."<<endl;
}
