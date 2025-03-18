#include <iostream>
#include <algorithm>

using namespace std;




int main(){
    int n;
    cin >> n;
    int grid[n][n];
    int dp[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    dp[0][0] = 0;

    for (int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], grid[i][0]);
        dp[0][i] = max(dp[0][i-1], grid[0][i]);
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            dp[i][j] = max(grid[i][j], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << min(dp[n-1][n-2], dp[n-2][n-1]);

    return 0;
}