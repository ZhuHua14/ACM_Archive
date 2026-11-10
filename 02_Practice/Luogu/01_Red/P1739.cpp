// P1739 表达式括号匹配
#include<bits/stdc++.h>
using namespace std;
stack<char> s;
string str;
int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            if(s.empty()){
                cout << "NO";
                return 0;
            }
            if(s.top() == '('){
                s.pop();
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    if(s.empty()){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}