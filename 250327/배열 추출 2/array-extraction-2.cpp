#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


int main(){
    int n;
    cin >> n;
    priority_queue<pair<int, int>> q;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;

        if (a != 0){
            q.push(make_pair(-abs(a), -a));
            continue;
        }

        if (q.empty()){
            cout << 0 << endl;
            continue;
        }
        
        cout << -q.top().second << endl;
        q.pop();
    }




    return 0;
}