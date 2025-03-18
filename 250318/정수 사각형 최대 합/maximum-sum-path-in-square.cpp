#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
int answer[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    answer[0][0] = grid[0][0];

    for (int i = 1; i < n; i++){
        answer[0][i] = answer[0][i-1] + grid[0][i];
        answer[i][0] = answer[i-1][0] + grid[i][0];
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            answer[i][j] = max(answer[i][j-1] + grid[i][j], answer[i-1][j] + grid[i][j]);
        }
    }

    cout << answer[n-1][n-1];

    return 0;
}
