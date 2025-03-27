#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


int main(){
    int n;
    cin >> n;
    priority_queue<int> plus_q;
    priority_queue<int> minus_q;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;

        if (a != 0){
            if (a > 0){
                plus_q.push(-a);
            } else{
                minus_q.push(a);
            }
            continue;
        }

        if (plus_q.empty() && !minus_q.empty()){
            cout << minus_q.top() << endl;
            minus_q.pop();
        } else if (!plus_q.empty() && minus_q.empty()){
            cout << -plus_q.top() << endl;
            plus_q.pop();
        } else if (!plus_q.empty() && !minus_q.empty()){
            if (abs(minus_q.top()) <= abs(plus_q.top())){
                cout << minus_q.top() << endl;
                minus_q.pop();
            } else{
                cout << -plus_q.top() << endl;
                plus_q.pop();
            }
        } else{
            cout << 0 << endl;
        }
    }




    return 0;
}