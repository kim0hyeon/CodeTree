#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, k, count = 0;
vector<vector<int>> grid;
vector<vector<bool>> visited;
queue<pair<int, int>> q;


void BFS(){
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first, y = current.second;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (tx > 0 && tx <= n && ty > 0 && ty <= n){
                if (grid[tx][ty] == 0 && !visited[tx][ty]){
                    visited[tx][ty] = true;
                    q.push(make_pair(tx, ty));
                    count++;
                }
            }
        }
    }
}

int main(){
    cin >> n >> k;
    grid = vector<vector<int>>(n+1, vector<int>(n+1));
    visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;

        if (!visited[x][y]){  // 이미 방문한 x, y일 경우 세지 않는다.
            count++;
            q.push(make_pair(x, y));
            visited[x][y] = true;

            BFS();
        }
    }

    cout << count;

    return 0;
}