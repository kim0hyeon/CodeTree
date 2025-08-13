#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()){
        auto pair = q.front();
        q.pop();
        int x = pair.first;
        int y = pair.second;

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= n && ny > 0 && ny <= m){
                if (!visited[nx][ny] && grid[nx][ny] == 1){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    grid = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    visited = vector<vector<bool>>(n+1, vector<bool>(m+1, false));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    BFS(1, 1);

    cout << visited[n][m];
    return 0;
}