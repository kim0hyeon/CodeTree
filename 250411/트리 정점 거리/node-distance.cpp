#include <iostream>
#include <vector>

using namespace std;

int result;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;


void DFS(int current, int target, int count){
    if (current == target) result = count;

    for (auto next : graph[current]){
        int node = next.first;
        int dist = next.second;

        if (!visited[node]){
            visited[node] = true;
            DFS(node, target, count+dist);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    graph = vector<vector<pair<int, int>>>(n+1);

    for (int i = 0; i < n-1; i++){
        int start, end, dist;
        cin >> start >> end >> dist;

        graph[start].push_back({end, dist});
        graph[end].push_back({start, dist});
    }

    for (int i = 0; i < m; i++){
        int start, end, count = 0;
        result = 0;
        cin >> start >> end;

        visited = vector<bool>(n+1, false);

        DFS(start, end, count);

        cout << result << endl;
    }


    return 0;
}