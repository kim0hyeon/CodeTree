#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;


int n, m;
vector<int> dist;
vector<vector<pair<int, int>>> route;

void BFS(int n){
    dist[n] = 0;

    queue<int> q;
    q.push(n);

    while (!q.empty()){
        int current = q.front();
        q.pop();

        for (auto next : route[current]){
            int nextNode = next.second;
            int cost = next.first;

            if (dist[nextNode] > dist[current] + cost){
                dist[nextNode] = dist[current] + cost;
                q.push(nextNode);
            }
        }

    }
}

int main(){
    cin >> n >> m;

    dist = vector<int>(n+1, INT_MAX);
    route = vector<vector<pair<int, int>>>(n+1);

    for (int i = 0; i < m; i++){
        int start, end, distance;
        cin >> end >> start >> distance;  // 거꾸로 이동해야하니까 시작과 끝 값을 바꿔 받는다.
        route[start].push_back({distance, end});
    }

    BFS(5);

    int max_val = 0;
    for (int i = 1; i <= n; i++){
        max_val = max(max_val, dist[i]);
    }

    cout << max_val;

    return 0;
}