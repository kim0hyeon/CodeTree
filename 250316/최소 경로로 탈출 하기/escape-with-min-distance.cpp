#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> step;
queue<pair<int, int>> q;

void BFS(){
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        int cur_step = step[x][y];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++){
            int tx = x+dx[i], ty = y+dy[i];

            if (tx > 0 && tx <= n && ty > 0 && ty <= m){
                if (grid[tx][ty] == 1 && !visited[tx][ty]){
                    step[tx][ty] = cur_step+1;
                    visited[tx][ty] = true;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    grid = vector<vector<int>>(n+1, vector<int>(m+1));
    visited = vector<vector<bool>>(n+1, vector<bool>(m+1, false));
    step = vector<vector<int>>(n+1, vector<int>(m+1));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    q.push(make_pair(1, 1));
    visited[1][1] = true;
    step[1][1] = 0;

    BFS();

    step[n][m] == 0 ? cout << -1 : cout << step[n][m];

    return 0;
}