#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
vector<vector<int>> grid;
vector<vector<int>> answer;
vector<vector<bool>> visited;
queue<pair<int, int>> q;


void BFS(){
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        int step = answer[x][y];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++){
            int tx = x + dx[i], ty = y + dy[i];

            if (tx > 0 && tx <= n && ty > 0 && ty <= n){
                if (grid[tx][ty] == 1 && !visited[tx][ty]){
                    visited[tx][ty] = true;
                    q.push(make_pair(tx, ty));
                    if (answer[tx][ty] > step+1) answer[tx][ty] = step+1;
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
        for (int j = 1; j <= n; j++) cin >> grid[i][j];
    }

    answer = vector<vector<int>>(n+1, vector<int>(n+1, n*n));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (grid[i][j] == 2){
                q.push(make_pair(i, j));
                visited[i][j] = true;
                answer[i][j] = 0;
                BFS();
                visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (answer[i][j] == n*n){
                if (grid[i][j] == 0) cout << -1 << " ";
                else if (grid[i][j] == 1) cout << -2 << " ";
            } else{
                cout << answer[i][j] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}