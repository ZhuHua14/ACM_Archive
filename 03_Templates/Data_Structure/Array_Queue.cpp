#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 10005;

int n;
class Queue{
    private:

    int q[MAXN], top = 1, back = 0, sz = 0;
    
    public:
    
    bool empty(){
        return sz? 0 : 1;
    }

    int size(){
        return sz;
    }

    int pop(){
        if(empty()) return INT_MIN;
        int ret = q[top];
        top++;
        top %= MAXN;
        sz--;
        return ret;
    }

    void push(int x){
        back++;
        back %= MAXN;
        sz++;
        q[back] = x;
    }

    int front(){
        return empty()? INT_MAX : q[top];
    }
};

Queue q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int op, x;
    while(n--){
        cin >> op;
        if(op == 1){
            cin >> x;
            q.push(x);
            //cerr << 1 << '\n';
        }
        else if(op == 2){
            if(q.pop() == INT_MIN){
                cout << "ERR_CANNOT_POP\n";
            }
            //cerr << 2 << '\n';
        }
        else if(op == 3){
            if(q.front() == INT_MAX){
                cout << "ERR_CANNOT_QUERY\n";
            }
            else cout << q.front() << '\n';
            //cerr << 3 << '\n';
        }
        else if(op == 4){
            cout << q.size() << '\n';
            //cerr << 4 << '\n';
        }
    }
    return 0;
}