#include <iostream>
#include <vector>

using namespace std;


int n, m;
vector<vector<int>> grid;

bool exist = false;

void DFS_exit(int x, int y){
    if (x == n && y == m)
        exist = true;
    
    // 수행시간을 고려해 만약 exist가 발견되었다면 더 이상 함수 진행할 필요 없음!
    if (x < n && grid[x+1][y] == 1 && !exist){  // x가 범위를 벗어나지 않고 다음 행이 진입 가능할 때
        DFS_exit(x+1, y);
    }
    if (y < m && grid[x][y+1] == 1 && !exist){  // y가 범위를 벗어나지 않고 다음 행이 진입 가능할 때
        DFS_exit(x, y+1);
    }
}

int main(){
    cin >> n >> m;
    grid = vector<vector<int>>(n+1, vector<int>(m+1));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    DFS_exit(1, 1);

    if (exist) cout << 1;
    else cout << 0;

    return 0;
}