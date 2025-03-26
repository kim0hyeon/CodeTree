#include <iostream>
#include <queue>

using namespace std;


int main(){
    int n;
    cin >> n;

    priority_queue<int> q;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }

    while (q.size() > 1){
        int a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();

        if (a != b){
            q.push(a-b);
        }
    }

    if (q.empty()) cout << -1;
    else cout << q.top();


    return 0;
}