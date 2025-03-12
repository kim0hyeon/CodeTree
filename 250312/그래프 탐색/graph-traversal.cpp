#include <iostream>
#include <vector>

using namespace std;


int n, m;
vector<vector<int>> graph;
vector<int> visited;
int answer = 0;

void DFS(int vertex){
    for (int i = 0; i < graph[vertex].size(); i++){
        int node = graph[vertex][i];
        if (visited[node] == 0){  // 아직 방문하지 않은 노드를 방문할 경우
            answer++;  // 방문한 노드의 개수를 1 증가시키고
            visited[node] = 1;  // 해당 노드를 방문했다고 체크하고
            DFS(node);  // 해당 노드에서 이동할 수 있는 노드를 찾아본다.
        }
    }
}

int main(){
    cin >> n >> m;

    graph = vector<vector<int>>(n);

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++){  // 아직 방문하지 않은 경우는 0
        visited.push_back(0);
    }
    visited[0] = 1;  // 1은 방문한 것으로 치기 때문에 1로 변경한다.

    DFS(0);
    cout << answer;

    return 0;
}