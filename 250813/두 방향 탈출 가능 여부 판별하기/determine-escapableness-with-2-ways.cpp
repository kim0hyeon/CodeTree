#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[] = {1, 0};
int dy[] = {0, 1};

void DFS(int x, int y){
    for (int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx > 0 && nx <= n && ny > 0 && ny <= m){
            if (!visited[nx][ny] && grid[nx][ny] == 1){
                visited[nx][ny] = true;
                DFS(nx, ny);
            }
        }
    }
}


int main(){
    cin >> n >> m;
    grid = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    visited = vector<vector<bool>> (n+1, vector<bool>(m+1, false));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    visited[1][1] = true;
    DFS(1, 1);

    if (visited[n][m]) 
        cout << 1;
    else 
        cout << 0;
    return 0;
}