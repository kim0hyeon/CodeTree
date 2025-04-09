#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
vector<bool> visited;
vector<vector<int>> graph;
map<int, int> coupling;

void DFS(int current){
    visited[current] = true;

    for (int next : graph[current]){
        if (!visited[next]){
            coupling[next] = current;
            DFS(next);
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    visited = vector<bool>(n+1, false);
    graph = vector<vector<int>>(n+1);

    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    DFS(1);

    for (int i = 2; i <= n; i++){
        cout << coupling[i] << endl;
    }

    return 0;
}