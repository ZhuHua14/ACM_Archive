#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 105;
int n;
vector<int> edge[MAXN];
int ind[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
    	int x;
    	do{
    		cin >> x;
    		edge[i].push_back(x);
    		ind[x]++;
    	}while(x != 0);
    	edge[i].pop_back();
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
    	if(ind[i] == 0){
    		q.push(i);
    	}	
    }
    int tp;
    while(!q.empty()){
    	tp = q.front();
    	q.pop();
    	cout << tp << ' ';
    	for(auto e : edge[tp]){
    		ind[e]--;
    		if(ind[e] == 0){
    			q.push(e);
    		}
    	}
    }
    return 0;
}