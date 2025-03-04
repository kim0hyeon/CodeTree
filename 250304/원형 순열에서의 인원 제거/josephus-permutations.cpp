#include <iostream>
#include <queue>

using namespace std;

void remove(queue<int> &q, int k){
    for (int i = 0; i < k-1; i++){
        q.push(q.front());
        q.pop();

    }
    cout << q.front() << " ";
    q.pop();
}

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;

    for (int i = 0; i < n; i++){
        q.push(i+1);
    }

    while (!q.empty()){
        remove(q, k);
    }

    return 0;
}
