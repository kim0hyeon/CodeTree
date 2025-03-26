#include <iostream>
#include <queue>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < m; i++){
        int a = pq.top();
        pq.pop();
        pq.push(a-1);
    }

    cout << pq.top();

    return 0;
}