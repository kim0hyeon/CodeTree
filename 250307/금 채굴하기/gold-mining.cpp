#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    int answer = 0;

    // 모든 (x, y) 중심에 대해
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){

            // k=0부터 어떤 적당한 최대치(예: n*2 정도)까지 다 시도
            // 사실 n 이상 넘어가면 비용이 너무 커지는 경우가 대부분이라
            // n 또는 2*n 정도까지만 확인해도 충분
            for(int k = 0; k <= 2*n; k++){
                // 채굴할 칸 = { (i, j) | abs(i-x) + abs(j-y) <= k }
                // 이 칸들의 '금 개수'를 센다
                int goldCount = 0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(abs(i - x) + abs(j - y) <= k){
                            goldCount += grid[i][j];
                        }
                    }
                }

                // 비용
                int cost = k*k + (k+1)*(k+1);
                // 이익 = (goldCount*m) - cost
                if(goldCount * m - cost >= 0){
                    // 손해가 아니면, answer 후보 갱신
                    answer = max(answer, goldCount);
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;
}