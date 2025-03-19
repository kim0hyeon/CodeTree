#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(m+1));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    for (int x = 2; x <= n; x++){
        for (int y = 2; y <= n; y++){
            for (int i = 1; i <= x-1; i++){
                for (int j = 1; j <= y-1; j++){
                    if (grid[x][y] > grid[i][j]){
                        dp[x][y] = max(dp[x][y], dp[i][j]+1);
                    }
                }
            }
        }
    }

    int max_val = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (max_val < dp[i][j]) max_val = dp[i][j];
        }
    }

    cout << max_val;

    return 0;
}