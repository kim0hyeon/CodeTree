#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, m, cnt, height;
vector<vector<int>> grid;
vector<vector<bool>> visited;


void DFS_search(int x, int y){
    visited[x][y] = true;  // 방문했다고 체크

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (tx >= 0 && tx < n && ty >= 0 && ty < m){
            if (grid[tx][ty] > height && !visited[tx][ty]){
                DFS_search(tx, ty);
            }
        }
    }
}


int main(){
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));  // 방문의 기본값은 false

    int high = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            high = max(high, grid[i][j]);
        }
    }

    // 초기값 설정
    int max_val = 0;
    int max_height = 1;

    for (int k = 1; k < high; k++){
        cnt = 0;
        height = k;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] > height && !visited[i][j]){  // 빗물보다 높이가 높고 아직 방문한 적이 없는 경우
                    cnt++;  // 집 발견!
                    DFS_search(i, j);  // 해당 집과 인접한 집들 모두 방문 표시
                }
            }
        }
        if (max_val < cnt){
            max_val = cnt;
            max_height = height;
        }
        visited = vector<vector<bool>>(n, vector<bool>(m, false));  // 다음 k에서 또 확인해야하므로 초기화한다.
    }

    cout << max_height << " " << max_val;

    return 0;
}