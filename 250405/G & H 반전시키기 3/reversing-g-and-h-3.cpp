#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> dp(n, 0);
    string origin, target;
    cin >> origin >> target;

    for (int i = 0; i < n; i++){
        if (origin[i] != target[i]){
            if (i == 0) 
                dp[i] = 1;
            else{
                dp[i] = dp[i-1]+1;

                if (dp[i-1] <= 3) dp[i-1] = 0;
                if (dp[i] == 5) dp[i] = 1;
            }
        }
    }

    int count = 0;
    for (int c : dp){
        if (c > 0) count++;
    }

    cout << count;

    return 0;
}