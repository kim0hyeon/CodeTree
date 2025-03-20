#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> vec(n+1);
    vector<int> dp(n+1);

    for (int i = 1; i <= n; i++){ 
        cin >> vec[i];
        dp[i] = vec[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}