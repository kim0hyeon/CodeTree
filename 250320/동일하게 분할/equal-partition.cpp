// 총 합이 2n이라고 하면 n, n으로 나뉘어야하는데
// 일단 순서는 상관이 없고, 순서를 보지 않으니 dp가 필요한가?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, total = 0;
    cin >> n;

    vector<int> vec(n);
    vector<int> dp(n+1, 0);
    for (int i = 0; i < n; i++){
        cin >> vec[i];
        total += vec[i];
    }

    sort(vec.begin(), vec.end());

    bool flag = false;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if (dp[j] + vec[i] == total/2){
                flag = true;
                break;
            }
            if (j == i-1){
                dp[i] = dp[j] + vec[i];
            }
        }
        if (flag) break;
    }

    if (total % 2 == 1 || !flag) cout << "No";
    else cout << "Yes";


    return 0;
}

// 누적해서 더하는 방식을 갖고가면 어떨까?
//