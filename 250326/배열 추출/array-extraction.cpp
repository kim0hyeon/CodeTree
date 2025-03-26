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

        if (a == 0){
            if (q.empty()) cout << 0 << endl;
            else{
                cout << q.top() << endl;
                q.pop();
            }
        } else{
            q.push(a);
        }
    }


    return 0;
}