#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<unordered_map<int, long long>> dp(4);

    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 2; j >= 0; j--){
            for (auto &pair : dp[j]){
                int currentsum = pair.first;
                long long ways = pair.second;
                dp[j+1][currentsum+arr[i]] += ways;
            }
        }
    }

    cout << dp[3][k];

    return 0;
}