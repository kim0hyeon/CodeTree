#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 1-indexed grid 및 dp 배열 선언
    vector<vector<int>> grid(n+1, vector<int>(n+1));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    // grid 입력
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    
    // 시작 위치 초기화
    dp[1][1] = grid[1][1];
    
    // 첫 행 채우기
    for (int j = 2; j <= n; j++){
        dp[1][j] = min(dp[1][j-1], grid[1][j]);
    }
    
    // 첫 열 채우기
    for (int i = 2; i <= n; i++){
        dp[i][1] = min(dp[i-1][1], grid[i][1]);
    }
    
    // 나머지 셀 채우기
    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= n; j++){
            dp[i][j] = max(min(dp[i-1][j], grid[i][j]), min(dp[i][j-1], grid[i][j]));
        }
    }
    
    // 최종 결과 출력
    cout << dp[n][n] << endl;
    
    return 0;
}
