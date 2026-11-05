#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n,k,l[MAXN];
bool check(int len){
	int nowcut = 0;
	for(int i = 1;i <= n;i++){
		nowcut += l[i] / len;	
	}
	if(nowcut >= k) return 1;
	return 0;
}
int main(){
	cin>>n>>k;
	int maxl = 0;
	for(int i = 1;i <= n;i++){
		cin>>l[i];
		maxl = max(l[i],maxl);
	}
	int left = 0,ans,right=maxl,mid;
	while(left + 1 < right){
		//cout<<left<<" "<<right<<endl;		
		//if(r = 1) break;
		mid = (left + right) / 2;
		//if(mid == 0) cout<<-1; return 0;
		if(check(mid)){
			ans	= mid;
			left = mid;
		}
		else{
			right = mid;
		}

	}
	cout<<left;
	return 0;
} 