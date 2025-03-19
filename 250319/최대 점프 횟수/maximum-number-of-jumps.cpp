#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int current_idx = 0;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (i-j <= arr[j] && current_idx >= j){
                dp[i] = max(dp[i], dp[j]+1);
                current_idx = i;
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}

// 시작 부분에서 끊기면 더 이상 세면 안됨
// 현재 위치 변수 추가