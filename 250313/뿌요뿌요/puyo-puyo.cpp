#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, cnt, current;
vector<vector<int>> grid;
vector<vector<bool>> visited;


void DFS_search(int x, int y){
    cnt++;
    visited[x][y] = true;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,1,-1};

    for (int i = 0; i < 4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n){
            if (grid[tx][ty] == current && !visited[tx][ty]){
                DFS_search(tx, ty);
            }
        }
    }
}


int main(){
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int max_val = 0;
    int block_cnt = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!visited[i][j]){
                cnt = 0;
                current = grid[i][j];
                DFS_search(i, j);
                max_val = max(max_val, cnt);  // 최대값을 다시 계산하고
                
                if (cnt >= 4){  // 이어지는 블록이 4개 이상인 경우
                    block_cnt++;  // 터지는 블록 하나 추가한다.
                }
                
            }
        }
    }

    cout << block_cnt << " " << max_val;
    return 0;
}