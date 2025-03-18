#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<int>> dp; // dp[i][j]는 (i, j)에서 시작하는 최장 증가 경로의 길이

// DFS를 통해 (i, j)에서 시작하는 최장 경로 길이를 계산
int dfs(int i, int j) {
    if (dp[i][j] != 0)
        return dp[i][j];

    int max_path = 1; // 현재 셀만 포함하는 경우 길이는 1
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 상하좌우 탐색
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > grid[i][j]) {
            max_path = max(max_path, 1 + dfs(ni, nj));
        }
    }
    dp[i][j] = max_path;
    return max_path;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    grid.resize(n, vector<int>(n));
    dp.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    // 모든 셀에 대해 DFS를 수행하여 최장 경로를 찾음
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans << "\n";
    return 0;
}









































// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>

// using namespace std;

// int n;
// vector<vector<int>> grid;
// vector<vector<int>> answer;
// vector<vector<int>> step;
// vector<vector<bool>> visited;
// queue<pair<int, int>> q;

// void BFS(){
//     while (!q.empty()){
//         pair<int, int> current = q.front();
//         q.pop();
//         int x = current.first, y = current.second;
//         int cur_step = step[x][y];

//         int dx[] = {-1, 1, 0, 0};
//         int dy[] = {0, 0, 1, -1};

//         for (int i = 0; i < 4; i++){
//             int tx = x + dx[i], ty = y + dy[i];

//             if (tx > 0 && tx <= n && ty > 0 && ty <= n){
//                 if (grid[x][y] < grid[tx][ty] && !visited[tx][ty]){
//                     q.push(make_pair(tx, ty));
//                     step[tx][ty] = step[x][y] + 1;
//                     visited[tx][ty] = true;
//                 }
//             }
//         }


//     }
// }

// int found_max(vector<vector<int>> &matrix){
//     int max_val = 0;

//     for (vector<int> &row : matrix){
//         if (!row.empty()) {
//             int row_max = *max_element(row.begin(), row.end());
//             max_val = max(max_val, row_max);
//         }
//     }

//     return max_val;
// }

// int main(){
//     cin >> n;
//     grid = vector<vector<int>>(n+1, vector<int>(n+1));
//     answer = vector<vector<int>>(n+1, vector<int>(n+1));
//     step = vector<vector<int>>(n+1, vector<int>(n+1));
//     visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));

//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= n; j++){
//             cin >> grid[i][j];
//         }
//     }

//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= n; j++){
//             // i,j에서 갈 수 있는 최장 거리를 확인하고 answer[i][j]에 넣는다.
//             q.push(make_pair(i, j));
//             visited[i][j] = true;
//             step[i][j] = 1;
//             BFS();
//             answer[i][j] = found_max(step);

//             // 다음을 체크해야하므로 변수들을 초기화한다.
//             visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
//             step = vector<vector<int>>(n+1, vector<int>(n+1));
//         }
//     }

//     cout << found_max(answer);

//     return 0;
// }