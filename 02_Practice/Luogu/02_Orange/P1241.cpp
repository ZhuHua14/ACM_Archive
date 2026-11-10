// P1241 括号序列
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 210;
struct Node{
	int cnt;
	char data;
};
int top;
Node s[MAXN];
void pop(){
	top--;
	return;
}
void add(Node node){
	s[++top] = node;
	return;
}
Node _top(){
	return s[top];
}
bool flag[MAXN];
string input;
Node nowtop,now;
char ans[MAXN],kuo[4] = {'(','[',']',')'};
/*bool iskuo(char ch){
	for(int i = 0; i <= 3; i++){
		if(ch == kuo[i]) return 1;
	}
	return 0;
}*/
int main(){
	cin>>input;
	int nowsize;
	for(int i = 0; i < input.size(); i++){
		now.data = input[i];
		now.cnt = i;
		if(now.data == ']' || now.data == ')'){
			nowtop = _top();
			if((nowtop.data == '[' && now.data ==']') || (nowtop.data == '(' && now.data ==')')){
				flag[now.cnt] = flag[nowtop.cnt] = 1;
				pop();
			}
			continue;
		}
		add(now);
	}
	for(int i = 0; i < input.size(); i++){
		if(flag[i] == 1){
			cout<<input[i];
		}
		else{
			if(input[i] == '(' || input[i] == ')') cout<<"()";
			else cout<<"[]";
		}
	}
	return 0;
}