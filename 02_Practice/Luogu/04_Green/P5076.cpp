// P5076 【深基16.例7】普通二叉树（简化版）
#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
multiset <int> tree;

void incert(int v){
	tree.insert(v);
}

int find_rank(int v){
	int rank = 0;
	multiset<int>::iterator it = tree.lower_bound(v);
	for(multiset<int>::iterator i = tree.begin(); i != it; i++){
		rank++;
	}
	return rank;
}

int find_data(int rank){
	multiset<int>::iterator it = tree.begin();
	for(int i = 1; i <= rank; i++){
		it++;
	}
	return *it;
}

int find_pre(int v){
	multiset<int>::iterator it = tree.lower_bound(v);
	it--;
	return *it;
}

int find_next(int v){
	return *tree.upper_bound(v);
}
int nowop,q,nowx;
int main(){
	cin>>q;
	incert(-INF);
	incert(INF);
	for(int i = 1; i <= q; i++){
		cin>>nowop>>nowx;
		switch(nowop){
			case 1:{
				cout<<find_rank(nowx)<<endl;
				break;
			}
			case 2:{
				cout<<find_data(nowx)<<endl;
				break;
			}
			case 3:{
				cout<<find_pre(nowx)<<endl;
				break;
			}
			case 4:{
				cout<<find_next(nowx)<<endl;
				break;
			}
			case 5:{
				incert(nowx);
				//cout<<nowcnt<<"  ";
				//output(tree[nowcnt]);
				break;
			}
			default:{
				break;
			}
		}
	}	
}