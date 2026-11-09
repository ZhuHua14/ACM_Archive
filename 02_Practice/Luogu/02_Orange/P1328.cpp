#include<bits/stdc++.h>
using namespace std;
int ar[210],br[210],n,at,bt,ascore,bscore;
int chat[5][5]={{0,-1,1,1,-1},
				{1,0,-1,1,-1},
				{-1,1,0,-1,1},
				{-1,-1,1,0,1},
				{1,1,-1,-1,0}
};
int main(){
	cin>>n>>at>>bt;
	for(int i=0;i<at;i++){
		cin>>ar[i];
	}
	for(int i=0;i<bt;i++){
		cin>>br[i];
	}
	for(int i=0;i<n;i++){
		switch(chat[ar[i%at]][br[i%bt]]){
			case 1: ascore++; break;
			case -1: bscore++; break;
		}
	}
	cout<<ascore<<" "<<bscore;
	return 0; 
}