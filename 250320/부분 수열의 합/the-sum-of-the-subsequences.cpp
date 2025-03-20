#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> dp(m+1, -1);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dp[0] = 0;
    for (int num : arr){
        for (int i = m; i > 0; i--){
            if (i-num >= 0 && dp[i-num] != -1){
                dp[i] = dp[i-num] + 1;
            }
        }
    }

    dp[m] == -1 ? cout << "No" : cout << "Yes";

    return 0;
}