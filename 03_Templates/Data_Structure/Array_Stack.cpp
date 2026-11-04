#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN = 1e6 + 5;

ull st[MAXN],top = 0;
int T;
int n;

void push(ull x){
    st[++top] = x ;
}

ull query(){
    return st[top];
}

ull pop(){
    return st[top--];
}

ull size(){
    return top;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        memset(st,0,sizeof(st));
        top = 0;
        string op;
        ull x;
        for(int i = 1; i <= n; i++){
            cin >> op;
            if(op == "push") cin >> x, push(x);
            else if(op == "size") cout << size() << '\n';
            else if(op == "pop"){
                if(top == 0){
                    cout << "Empty\n";
                }
                else pop();
            }
            else if(op == "query"){
                if(top == 0){
                    cout << "Anguei!\n";
                }
                else cout << query() << '\n';
            }
        }
    }
    return 0;
}