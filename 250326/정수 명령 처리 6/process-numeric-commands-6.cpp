#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main(){
    int n;
    cin >> n;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;

        if (cmd == "push"){
            int a;
            cin >> a;
            pq.push(a);
        } else if (cmd == "size"){
            cout << pq.size() << endl;
        } else if (cmd == "empty"){
            pq.empty() ? cout << 1 << endl : cout << 0 << endl;
        } else if (cmd == "pop"){
            cout << pq.top() << endl;
            pq.pop();
        } else if (cmd == "top"){
            cout << pq.top() << endl;
        }
    }



    return 0;
}