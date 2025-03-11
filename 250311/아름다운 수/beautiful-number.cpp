#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    
    // dp[i][last]: 길이 i인 아름다운 수 중 마지막 블록의 숫자가 last인 경우의 수.
    // last == 0은 아직 아무 블록도 선택되지 않은 초기 상태.
    vector<vector<ll>> dp(n+1, vector<ll>(5, 0));
    dp[0][0] = 1;
    
    // i: 현재까지 구성한 자리수
    for(int i = 0; i <= n; i++){
        // last: 마지막 블록의 숫자 (0이면 아직 없음)
        for(int last = 0; last < 5; last++){
            if(dp[i][last] == 0) continue;
            // 다음 블록의 숫자는 1~4 중 last와 달라야 함.
            for(int d = 1; d <= 4; d++){
                if(last == d) continue;
                // d에 대해 블록의 길이는 d, 2*d, 3*d, ...여야 함.
                for(int k = 1; i + k * d <= n; k++){
                    dp[i + k * d][d] += dp[i][last];
                }
            }
        }
    }
    
    ll answer = 0;
    for(int d = 1; d <= 4; d++){
        answer += dp[n][d];
    }
    
    cout << answer << "\n";
    return 0;
}
