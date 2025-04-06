#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>

using namespace std;

int n, m;
vector<int> dist;
vector<vector<pair<int, int>>> graph;  // 수정: vector of vector로 변경

void dijkstra(int source) {
    // 우선순위 큐에는 (거리, 노드) 쌍을 넣어 최단 거리가 작은 순서로 추출할 수 있게 하는 것이 일반적입니다.
    // 여기서는 최소 힙을 사용하기 위해 priority_queue의 비교함수를 반대로 사용합니다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }

    q.push({0, source});
    dist[source] = 0;

    while (!q.empty()){
        int current_dist = q.top().first;
        int current = q.top().second;
        q.pop();

        if (current_dist > dist[current])
            continue;

        for (auto &edge : graph[current]){
            int next_node = edge.first;
            int weight = edge.second;
            int new_dist = dist[current] + weight;
            if (new_dist < dist[next_node]){
                dist[next_node] = new_dist;
                q.push({new_dist, next_node});
            }
        }
    }
}

int main(){
    cin >> n >> m;

    dist = vector<int>(n+1, INT_MAX);
    graph = vector<vector<pair<int, int>>>(n+1);  // 수정: vector of vector로 초기화

    for (int i = 1; i <= m; i++){
        int start, end, price;
        cin >> start >> end >> price;
        graph[start].push_back(make_pair(end, price));
    }

    dijkstra(1);

    for (int i = 2; i <= n; i++){
        if (dist[i] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}
