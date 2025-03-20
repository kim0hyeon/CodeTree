#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> costs(n);
    vector<int> weights(n);
    vector<int> dp(m+1, -1);

    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> costs[i];
        dp[weights[i]] = costs[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < n; j++){
            if (i-weights[j] >= 0 && dp[i-weights[j]] != -1){
                dp[i] = max(dp[i], dp[i-weights[j]] + costs[j]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    
    return 0;
}