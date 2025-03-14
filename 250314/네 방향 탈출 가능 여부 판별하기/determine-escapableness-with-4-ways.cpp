#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
bool finds = false;

void BFS_search(int x, int y){
    if (x == n && y == m) {
        finds = true;
        return;
    }

    visited[x][y] = true;

    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    for (int i = 0; i < 4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (tx > 0 && tx <= n && ty > 0 && ty <= m){
            if (grid[tx][ty] == 1 && !visited[tx][ty]){
                BFS_search(tx, ty);
            }
        }
    }

    
}

int main(){
    cin >> n >> m;
    grid = vector<vector<int>>(n+1, vector<int>(m+1));
    visited = vector<vector<bool>>(n+1, vector<bool>(m+1, false));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    BFS_search(1, 1);

    finds ? cout << 1 : cout << 0;

    return 0;
}