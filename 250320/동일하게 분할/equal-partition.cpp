#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int total = 0;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
        total += vec[i];
    }
    
    // 총합이 홀수면 두 그룹으로 똑같이 나누는 것은 불가능합니다.
    if (total % 2 != 0) {
        cout << "No";
        return 0;
    }
    
    int half = total / 2;
    // dp[i][j] : 첫 i개의 원소를 사용해서 합 j를 만들 수 있으며, 그때 사용한 원소 개수를 저장합니다.
    // 만들 수 없는 경우 -1을 저장합니다.
    vector<vector<int>> dp(n + 1, vector<int>(half + 1, -1));
    
    // 0개의 원소로 합 0을 만드는 것은 가능하며, 사용한 원소 개수는 0입니다.
    dp[0][0] = 0;
    
    // 각 원소에 대해 포함/미포함 경우를 고려합니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= half; j++) {
            if (dp[i][j] != -1) {
                // 원소 i를 사용하지 않는 경우: 원래 값 유지
                if (dp[i + 1][j] < dp[i][j])
                    dp[i + 1][j] = dp[i][j];
                
                // 원소 i를 포함하는 경우 (합이 half를 넘지 않는다면)
                if (j + vec[i] <= half) {
                    int newCount = dp[i][j] + 1;
                    if (dp[i + 1][j + vec[i]] < newCount)
                        dp[i + 1][j + vec[i]] = newCount;
                }
            }
        }
    }
    
    // dp[n][half]가 0이면 빈 집합인 경우이고, n이면 전체 집합을 사용한 경우이므로 두 경우 모두 제외해야 합니다.
    if (dp[n][half] > 0 && dp[n][half] < n)
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}