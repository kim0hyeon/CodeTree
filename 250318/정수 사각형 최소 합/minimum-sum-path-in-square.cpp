#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<int>> answer;

int main() {
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n));
    answer = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    answer[0][n-1] = grid[0][n-1];

    for (int i = n-2; i >= 0; i--){
        answer[0][i] = answer[0][i+1] + grid[0][i];
    }

    for (int i = 1; i < n; i++){
        answer[i][n-1] = answer[i-1][n-1] + grid[i][n-1];
    }

    for (int i = 1; i < n; i++){
        for (int j = n-2; j >= 0; j--){
            answer[i][j] = min(answer[i][j+1] + grid[i][j], answer[i-1][j] + grid[i][j]);
        }
    }

    cout << answer[n-1][0];

    return 0;
}
