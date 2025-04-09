#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, max_val, max_node;
vector<bool> visited;
vector<vector<pair<int, int>>> graph;


void DFS(int current, int middle_sum){
    visited[current] = true;

    for (const auto &pair : graph[current]){
        int node = pair.first;
        int dist = pair.second;

        if (!visited[node]){
            if (middle_sum + dist > max_val){
                max_val = middle_sum + dist;
                max_node = node;
            }

            DFS(node, middle_sum + dist);
        }
    }
}

int main(){
    cin >> n;

    visited = vector<bool>(n+1, false);
    graph = vector<vector<pair<int, int>>>(n+1);


    for (int i = 0; i < n-1; i++){
        int start, end, dist;
        cin >> start >> end >> dist;

        graph[start].push_back({end, dist});
        graph[end].push_back({start, dist});
    }

    // 임의로 정한 1번 노드부터 최대 거리 탐색 시작
    max_val = 0;
    DFS(1, 0);

    // 그래프 방문기록 초기화하고 max_node에서부터 탐색 시작
    visited = vector<bool>(n+1, false);
    max_val = 0;
    DFS(max_node, 0);

    cout << max_val;

    return 0;
}