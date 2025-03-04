#include <iostream>
#include <queue>
#include <string>

using namespace std;


int main(){
    int n, num;
    string cmd;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++){
        cin >> cmd;

        if (cmd == "push"){
            cin >> num;
            q.push(num);
        } else if (cmd == "pop"){
            cout << q.front() << endl;
            q.pop();
        } else if (cmd == "size"){
            cout << q.size() << endl;
        } else if (cmd == "empty"){
            cout << q.empty() << endl;
        } else if (cmd == "front"){
            cout << q.front() << endl;
        }
    }

    return 0;
}