#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 그 다음 녀석이 이후까지의 녀석중에 최대를 정하면 되는데
    int dp[n];
    dp[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--){
        dp[i] = max(dp[i+1], arr[i]);
    }

    int max_val = INT_MIN;
    for (int i = 0; i < n-1; i++){
        max_val = max(max_val, dp[i+1] - arr[i]);
    }

    max_val < 0 ? cout << 0 : cout << max_val;

    return 0;
}