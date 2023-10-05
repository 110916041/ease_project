#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int menu(){
	int i;
	cout<<"     請選擇下列的遊戲"<<endl;
	cout<<"     1. 骰子遊戲比大"<<endl;
	cout<<"     2. 骰子遊戲比小"<<endl;
	cout<<"     3. 撲克牌遊戲比大"<<endl;
	cout<<"     4. 撲克牌遊戲比小"<<endl; 
	cout<<"     0. 離開"<<endl;
	cout<<"     請選擇(0,1,2,3,4)  ";
	cin>>i;
	return i;
}

int main() {
	int s,computer,you;
	int q[52]={0};        //撲克牌
	int a,b,c,d,e,f;      //撲克牌 
	int x=0,y=0,z=0,w=0,g=0;            //x 玩家骰子贏     y骰子輸   g骰子平手  z撲克牌贏    w撲克牌輸 
	srand(time(NULL));
	while(s=menu()){
		switch(s){
			case 1:{
    			cout<<"1，骰子比大";
    			cout<<endl;
				computer=(rand()%6)+1;
				you=(rand()%6)+1;
				if(you<computer){
					cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you loss~"<<endl;
					y++; 
				}
				if(you>computer){
					cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you win!"<<endl;
					x++;
				}
				if(you==computer){
					cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"The same!"<<endl;
					g++;
				}
				break;
			}
			case 2:{
				cout<<"2，骰子比小";
				cout<<endl;
				computer=(rand()%6)+1;
				you=(rand()%6)+1;
				if(you<computer){
					cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you win!"<<endl;
					x++;
				}
				if(you>computer){
					cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"you loss~"<<endl;
					y++;
				}
				if(you==computer){
					cout<<"you="<<you<<' '<<"computer="<<computer<<' '<<"The same!"<<endl;
					g++;
				}
				break;
			}
			case 3:{
				cout<<"3，撲克牌比大";
				cout<<endl;
				a=(rand()%52);
				q[a]=1;               //取不重複 
				do{
					b=rand()%52;
				}while(q[b]!=0);
				c=a%4;                //電腦 
				d=b%4;                //玩家 
				e=a/4+1;
				f=b/4+1;
				cout<<"電腦的牌是";
				switch(c){
					case 0:
						cout<<"梅花"<<'('<<e<<')'<<endl;
						break;
					case 1:
						cout<<"方塊"<<'('<<e<<')'<<endl;
						break;
					case 2:
						cout<<"愛心"<<'('<<e<<')'<<endl;
						break;
					case 3:
						cout<<"黑桃"<<'('<<e<<')'<<endl;
						break;
					}
					cout<<"你的牌是";
				switch(d){
					case 0:
						cout<<"梅花"<<'('<<f<<')'<<endl;
						break;
					case 1:
						cout<<"方塊"<<'('<<f<<')'<<endl;
						break;
					case 2:
						cout<<"愛心"<<'('<<f<<')'<<endl;
						break;
					case 3:
						cout<<"黑桃"<<'('<<f<<')'<<endl;
						break;
					}
					if(a<b){
						cout<<"You win!"<<endl;
						z++;
					}
					if(a>b){
						cout<<"You lose~"<<endl;
						w++;
					}
				break;
			}    
			case 4:{
				cout<<"4,撲克牌比小";
				cout<<endl;
				a=(rand()%52);
				q[a]=1;               //取不重複 
				do{
					b=rand()%52;
				}while(q[b]!=0);
				c=a%4;                //電腦 
				d=b%4;                //玩家 
				e=a/4+1;
				f=b/4+1;
				cout<<"電腦的牌是";
				switch(c){
					case 0:
						cout<<"梅花"<<'('<<e<<')'<<endl;
						break;
					case 1:
						cout<<"方塊"<<'('<<e<<')'<<endl;
						break;
					case 2:
						cout<<"愛心"<<'('<<e<<')'<<endl;
						break;
					case 3:
						cout<<"黑桃"<<'('<<e<<')'<<endl;
						break;
					}
					cout<<"你的牌是";
				switch(d){
					case 0:
						cout<<"梅花"<<'('<<f<<')'<<endl;
						break;
					case 1:
						cout<<"方塊"<<'('<<f<<')'<<endl;
						break;
					case 2:
						cout<<"愛心"<<'('<<f<<')'<<endl;
						break;
					case 3:
						cout<<"黑桃"<<'('<<f<<')'<<endl;
						break;
					}
					if(a>b){
						cout<<"You win!"<<endl;
						z++;
					}
					if(a<b){
						cout<<"You lose~"<<endl;
						w++;
					}
				break;
				}
		default:
			cout<<"輸入錯誤，請重新輸入!!!"  <<endl;     
			}
		if(z+w>=26){
			cout<<"牌庫以空，請選擇骰子遊戲或是離開重玩"<<endl;
			}
		} 
	cout<<"0"<<endl;
	cout<<"最終戰績"<<endl;
	cout<<"骰子你贏"<<x<<"次，輸"<<y<<"次，"<<"平手"<<g<<"次。"<<endl;
	cout<<"撲克牌你贏"<<z<<"次，輸"<<w<<"次。"<<endl;
	cout<<"Thanks for using, bye."<<endl;
	
}
