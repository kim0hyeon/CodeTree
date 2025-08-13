#include <iostream>
#include <vector>

using namespace std;


int n, m;
int ans = 0;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int current){
    for (int next : graph[current]){
        if (!visited[next]){
            visited[next] = true;
            ans++;
            DFS(next);
        }
    }
}

int main(){
    cin >> n >> m;
    graph = vector<vector<int>> (n+1);
    visited = vector<bool>(n+1, false);

    for (int i = 0; i < m; i++){
        int left, right;
        cin >> left >> right;

        graph[left].push_back(right);
        graph[right].push_back(left);
    }

    visited[1] = true;
    DFS(1);

    cout << ans;
    return 0;
}