#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    int N, num;
    string cmd;
    deque<int> dq;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "push_front"){
            cin >> num;
            dq.push_front(num);
        } else if (cmd == "push_back"){
            cin >> num;
            dq.push_back(num);
        } else if (cmd == "pop_front"){
            cout << dq.front() << endl;
            dq.pop_front();
        } else if (cmd == "pop_back"){
            cout << dq.back() << endl;
            dq.pop_back();
        } else if (cmd == "empty"){
            dq.empty() == true ? cout << 1 << endl : cout << 0 << endl;
        } else if (cmd == "front"){
            cout << dq.front() << endl;
        } else if (cmd == "back"){
            cout << dq.back() << endl;
        } else if (cmd == "size"){
            cout << dq.size() << endl;
        }
    }


    return 0;
}
