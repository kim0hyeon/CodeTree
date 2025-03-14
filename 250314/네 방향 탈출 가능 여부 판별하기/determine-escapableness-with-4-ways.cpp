#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

bool finds = false;

void BFS_search(){
    while (!q.empty()){
        pair<int, int> cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (tx > 0 && tx <= n && ty > 0 && ty <= m){
                if (grid[tx][ty] == 1 && !visited[tx][ty]){
                    q.push(make_pair(tx,ty));
                    visited[tx][ty] = true;
                }
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

    q.push(make_pair(1, 1));
    visited[1][1] = true;

    BFS_search();

    cout << visited[n][m];

    return 0;
}