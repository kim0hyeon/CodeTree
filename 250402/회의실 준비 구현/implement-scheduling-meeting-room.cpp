#include <iostream>
#include <queue>

using namespace std;


int main(){
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        pq.push(make_pair(-end, start));
    }

    int ans = 0;
    int right = 0;
    while (!pq.empty()){
        auto pair = pq.top();
        pq.pop();
        
        if (pair.second >= right){
            right = -pair.first;
            ans++;
        }
    }

    cout << ans;

    return 0;
}