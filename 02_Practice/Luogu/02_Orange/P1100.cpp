// P1100 高低位交换
#include<bits/stdc++.h>
using namespace std;

unsigned int n,nr,nl;
int main(){
	cin>>n;
	nr = n << 16;
	nl = n >> 16;
	cout<<(nr ^ nl);
	return 0;
}