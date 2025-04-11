#include <iostream>
#include <vector>

using namespace std;

int count = 0, erase_node;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int current){
    if (graph[current].size() == 0){
        count++;
    } else if (graph[current].size() == 1 && graph[current][0] == erase_node){
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

    // 해당 노드 자식 노드 연결을 끊어버리고 해당 노드와 부모 노드와의 연결도 끊어야 한다.
    cin >> erase_node;
    visited[erase_node] = true;

    


    if (!visited[root]){
        visited[root] = true;
        DFS(root);
    }

    cout << count;

    return 0;
}