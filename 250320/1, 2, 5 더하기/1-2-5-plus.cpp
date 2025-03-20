#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;

    int arr[] = {1,2,5};
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++){
        for (int num : arr){
            if (i-num > 0){
                dp[i] += dp[i-num];
            } else if (i - num == 0){
                dp[i] += 1;
            }
        }
    }

    cout << dp[n];

    return 0;
}

// 모든 방법의 수를 생각해야해..
// 순서가 다르면 다른 조합이라고 생각하고...
// 2를 생각해 보자. 그냥 2가 들어가도 되고 1,1이 들어가도 돼
// 3을 생각해 보면 2를 만드는 방법 2가지 + 1