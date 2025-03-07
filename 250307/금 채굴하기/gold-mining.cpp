#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int GetNumOfGold(vector<vector<int>> grid, int row, int col, int k){
    int num_of_gold = 0;

    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid.size(); j++){
            if (abs(row-i) + abs(col - j) <= k)
                num_of_gold += grid[i][j];
        }
    }

    return num_of_gold;
}

int main(){
    int max_gold = 0;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            cin >> grid[row][col];
        }
    }

    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            for (int k = 0; k <= 2*(n-1); k++){
                int num_of_gold = GetNumOfGold(grid, row, col, k);

                if (num_of_gold * m >= pow(k,2) + pow(k+1,2)){
                    max_gold = max(max_gold, num_of_gold);
                }
            }
        }
    }

    cout << max_gold;

    return 0;
}