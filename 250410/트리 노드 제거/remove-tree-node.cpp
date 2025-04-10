#include <iostream>
#include <vector>

using namespace std;

int count = 0;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int current){
    if (graph[current].size() == 0){
        count++;
    }
    
    for (int next : graph[current]){
        if (!visited[next]){
            visited[next] = true;
            DFS(next);
        }
    }
}

int main(){
    int n, root;
    cin >> n;

    graph = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    
    for (int i = 0; i < n; i++){
        int parent;
        cin >> parent;

        if (parent != -1)
            graph[parent].push_back(i);

        if (parent == -1) root = i;  // root노드를 체크한다.
    }

    int erase_node;
    cin >> erase_node;

    visited[erase_node] = true;  // 연결을 끊고 싶은 노드는 이미 방문한 것으로 체크.

    if (!visited[root]){
        visited[root] = true;
        DFS(root);
    }

    cout << count;

    return 0;
}