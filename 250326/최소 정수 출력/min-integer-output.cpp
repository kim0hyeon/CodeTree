#include <iostream>
#include <queue>

using namespace std;


int main(){
    int n;
    cin >> n;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++){
        int cmd;
        cin >> cmd;

        if (cmd == 0){
            if (pq.empty()) cout << 0 << endl;
            else{
                int a = pq.top();
                pq.pop();
                cout << -1 * a << endl;
            }
        } else{
            pq.push(cmd * -1);
        }
    }



    return 0;
}