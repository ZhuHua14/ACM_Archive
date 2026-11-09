#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
stack<int> s;
void clear(){
	while(!s.empty()){
		s.pop();
	}
	return;
}

bool check(int cnt,int* lpush,int* lpop){
	//cout<<cnt;
	/*for(int i = 1; i <= cnt; i++){
		cout<<lpush[i]<<' '<<lpop[i]<<endl;
	}*/
	int p = 1;
	for(int i = 1; i <= cnt; i++){
		s.push(lpush[i]);
		while((!s.empty()) && s.top() == lpop[p]){
			s.pop();
			p++;
		}
	}
	return s.empty();
}

int q,n,nowpop[MAXN],nowpush[MAXN];

int main(){
	cin>>q;
	//freopen("4387.in","r",stdin);
	//freopen("4387.out","w",stdout);
	for(int i = 1; i <= q; i++){
		cin>>n;	
		for(int j = 1; j <= n; j++){
			cin>>nowpush[j];
		}
		for(int j = 1; j <= n; j++){
			cin>>nowpop[j];
		}
		if(check(n,nowpush,nowpop)){
			cout<<"Yes";
		}
		else{
			cout<<"No";
		}
		cout<<endl;
		clear();
	}
	//fclose("4387.in");
	//fclose("4387.out");
	return 0;
}