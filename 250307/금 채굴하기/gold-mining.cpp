#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int find_gold(vector<vector<int>> &grid, int x, int y, int k, int price){
    // k가 n 이상으로 커지면 더 커 봐야 어차피 수익이 날 수 없으므로 종료
    if (k >= grid.size()) return 0;  

    int n = grid.size();
    int countGold = 0;
    int rowIndex = 0;  // (x-k) 행부터 세면서, 몇 번째 row인지 센다

    // 마름모 범위: i in [x-k, x+k]
    for (int i = x - k; i <= x + k; i++) {
        // 이 행에서 스킵(skip)할 칸 개수와 체크(check)할 칸 개수
        int skip = abs(rowIndex - k);         
        int check = (k * 2 + 1) - (skip * 2); 

        // 열(col) 범위: j in [y-k, y+k]
        int col = y - k;
        
        // 먼저 스킵해야 하는 칸들을 처리(실제 채굴 범위가 아직 아니므로 그냥 건너뛴다)
        while (skip > 0 && col <= (y + k)) {
            // 스킵은 “마름모 모양상” 채굴 대상이 아니므로 그냥 col만 증가
            skip--;
            col++;
        }

        // 이제 check 개수만큼 “마름모 모양상 채굴해야 할 칸”을 순회
        while (check > 0 && col <= (y + k)) {
            // 이 칸이 실제 격자 범위 안에 있으면, 금을 센다
            if (i >= 0 && i < n && col >= 0 && col < n) {
                countGold += grid[i][col];
            }
            check--;
            col++;
        }
        rowIndex++;
    }

    // 총 수익 = (채굴한 금 개수 × 금 가격)
    // 총 비용 = k^2 + (k+1)^2
    // 순이익이 음수면 손해이므로 무효
    int totalProfit = (countGold * price) - (k * k + (k + 1) * (k + 1));

    if (totalProfit < 0) {
        // 손해라면, 이 k는 안 쓰고 더 큰 k로 시도
        return max(0, find_gold(grid, x, y, k+1, price));
    } else {
        // 손해가 아니면 현재 k에서 캔 금 개수 vs 더 큰 k에서 캘 수 있는 금 개수 비교
        int biggerK = find_gold(grid, x, y, k+1, price);
        return max(countGold, biggerK);
    }
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

    cout << max_val << endl;
    return 0;
}