#include<bits/stdc++.h>
using namespace std;

map <string,int> m;

void insert(string name,int score){
	m[name] = score;
	cout<<"OK\n";
	return;
}

void find(string name){
	auto it = m.find(name);
	if(it != m.end()){
		cout<<m[name]<<endl;
		return;
	}
	else{
		cout<<"Not found\n";
		return;	
	}
}                  

void erase(string name){
	auto it = m.find(name);
	if(it != m.end()){
		m.erase(it);
		cout<<"Deleted successfully\n";
		return;
	}
	else{
		cout<<"Not found\n";
		return;	
	}
}

void sum(){
	cout<<m.size()<<endl;
	return;
}
int n;
int main(){
	cin>>n;
	int op,nowscore;
	string nowname;
	for(int i = 1; i <= n; i++){
		cin>>op;
		switch(op){
			case 1:{
				cin>>nowname>>nowscore;
				insert(nowname,nowscore);
				break;
			}
			case 2:{
				cin>>nowname;
				find(nowname);
				break;
			}
			case 3:{
				cin>>nowname;
				erase(nowname);
				break;
			}
			case 4:{
				sum();
				break;
			}
		}
	}
	return 0;
}