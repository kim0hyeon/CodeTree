#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool contains(vector<int> &vec, int num){
    return find(vec.begin(), vec.end(), num) != vec.end();
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<vector<int>> check(m+1);  // dp의 각 위치에서 고를 수 있는 숫자들을 나타내기 위한 배열
    vector<int> dp(m+1, INT_MAX);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    dp[0] = 0;
    for (int i = 1; i <= m; i++){
        for (int num : arr){
            if (i-num >= 0 && dp[i-num] != INT_MAX && !contains(check[i-num], num)){
                dp[i] = min(dp[i], dp[i-num]+1);
                check[i] = check[i-num];
                check[i].push_back(num);
            }
        }
    }

    dp[m] == INT_MAX ? cout << -1 : cout << dp[m];

    return 0;
}