#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> memo;  // -1: 아직 계산하지 않음, 0: 도착 불가능, 1: 도착 가능

bool DFS_exit(int x, int y) {
    // 목적지에 도착하면 true 리턴
    if (x == n && y == m)
        return true;
    
    // 이미 계산한 경우 저장된 값을 리턴
    if (memo[x][y] != -1)
        return memo[x][y];
    
    bool canReach = false;
    
    // 아래쪽으로 이동 가능한 경우
    if (x < n && grid[x+1][y] == 1) {
        canReach = DFS_exit(x+1, y);
    }
    
    // 만약 아래쪽에서 목적지에 도달하지 못하면 오른쪽으로 이동 시도
    if (!canReach && y < m && grid[x][y+1] == 1) {
        canReach = DFS_exit(x, y+1);
    }
    
    memo[x][y] = canReach;  // 결과 저장
    return canReach;
}

int main(){
    cin >> n >> m;
    grid = vector<vector<int>>(n+1, vector<int>(m+1));
    memo = vector<vector<int>>(n+1, vector<int>(m+1, -1)); // -1로 초기화

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    cout << (DFS_exit(1, 1) ? 1 : 0);

    return 0;
}
