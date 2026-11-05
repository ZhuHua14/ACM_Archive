#include<bits/stdc++.h>
using namespace std;
int numneed[10] = {6,2,5,5,4,5,6,3,7,6};
int need(int num){
	int nowneed = 0,nowp = 0;
	if(num == 0) return numneed[0];
	while(num != 0){
		nowp = num % 10;
		nowneed += numneed[nowp];
		num /= 10;
	}
	return nowneed;
}
int n,ans,c;
int main(){
	cin>>n;
	n -= 4;
	for(int i = 0; i <= 1111; i++){
		for(int j = 0;j <= 1111; j++){
			c = i + j;
			if(n - (need(i) + need(j) + need(c)) == 0){
				ans++;
			}	
		}
	}
	cout<<ans;
	return 0;
}