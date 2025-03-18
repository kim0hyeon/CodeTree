#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<int>> answer;
vector<vector<int>> step;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

void BFS(){
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        int cur_step = step[x][y];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++){
            int tx = x + dx[i], ty = y + dy[i];

            if (tx > 0 && tx <= n && ty > 0 && ty <= n){
                if (grid[x][y] < grid[tx][ty] && !visited[tx][ty]){
                    q.push(make_pair(tx, ty));
                    step[tx][ty] = step[x][y] + 1;
                    visited[tx][ty] = true;
                }
            }
        }


    }
}

int found_max(vector<vector<int>> &matrix){
    int max_val = 0;

    for (vector<int> &row : matrix){
        if (!row.empty()) {
            int row_max = *max_element(row.begin(), row.end());
            max_val = max(max_val, row_max);
        }
    }

    return max_val;
}

int main(){
    cin >> n;
    grid = vector<vector<int>>(n+1, vector<int>(n+1));
    answer = vector<vector<int>>(n+1, vector<int>(n+1));
    step = vector<vector<int>>(n+1, vector<int>(n+1));
    visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            // i,j에서 갈 수 있는 최장 거리를 확인하고 answer[i][j]에 넣는다.
            q.push(make_pair(i, j));
            visited[i][j] = true;
            step[i][j] = 1;
            BFS();
            answer[i][j] = found_max(step);

            // 다음을 체크해야하므로 변수들을 초기화한다.
            visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
            step = vector<vector<int>>(n+1, vector<int>(n+1));
        }
    }

    cout << found_max(answer);

    return 0;
}