// 1칸, 2칸, 3칸.. 마름모 모양으로 넓어지는식으로 코드 짜면 될거같은데
// 맨 처음 1칸을 해보고, 1칸이 된다하면 2칸으로, 된다하면 3칸으로, 만약 3칸이 안되면 2칸의 값을 리턴하는 방식으로.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int find_gold(vector<vector<int>> &grid, int x, int y, int k, int price){
    if (x-k < 0 || y-k < 0 || x+k >= grid.size() || y+k >= grid[0].size()) return 0; // 범위를 벗어나는 경우 0 리턴

    int count = 0;
    int row = 0;  // 0행부터 시작
    for (int i = x-k; i <= x+k; i++){
        int skip = abs(row-k);  // 각 행마다 이루어져야 할 스킵의 개수
        int check = (k * 2 + 1) - (skip * 2);  // 각 행마다 채크해야할 칸의 개수

        for (int j = y-k; j <= y+k; j++){
            if (skip > 0){  // 스킵해야 할 녀석이 있다면 check하기 전에 먼저 모두 스킵한다.
                skip--;
                continue;
            }
            if (check > 0){
                count += grid[i][j];  // 해당 칸에 금이 있다면 +1이 자동으로 되고, 없다면 0을 더하기때문에 값이 유지된다.
                check--;  // 체크 한번 했으니 체크해야할 개수 -1
                continue;
            }
        }
        row++;  // 다음 행으로 넘어갔으니 +1
    }

    int total = (count * price) - (pow(k,2) + pow(k+1, 2));  // 총계를 계산한다.

    // 총계가 0 미만이면 손해를 보는 경우이므로 제외시켜야해서 count대신에 0을 넣는다.
    if (total < 0)
        return max(0, find_gold(grid, x, y, k+1, price));
     else
        return max(count, find_gold(grid, x, y, k+1, price));  // 더 큰 마름모가 존재할 수도 있으므로 total과 다음 마름모를 비교한다.
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int max_val = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            max_val = max(max_val, find_gold(grid, i, j, 0, m));
        }
    }

    cout << max_val;


    return 0;
}