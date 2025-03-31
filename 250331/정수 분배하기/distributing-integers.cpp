#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<int> v;

bool IsPossible(int max_num){
    int count = 0;
    for (int i = 0; i < n; i++){
        count += v[i] / max_num;
    }

    return count >= m;
}

int main(){
    cin >> n >> m;
    v = vector<int>(n);

    int max_val = INT_MIN;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        max_val = max(max_val , v[i]);
    }

    int left = 1;
    int right = max_val;
    int ans = 0;

    while (left <= right){
        int mid = (left + right) / 2;

        if (IsPossible(mid)){  // 중심값이 가능하다면? 더 큰 숫자에서 찾아봐도 됨.
            ans = max(ans, mid);
            left = mid+1;
        } else{ // 중심값이 불가능하다면? 더 작은 숫자에서 찾아봐야됨
            right = mid-1;
        }
    }

    cout << ans;

    return 0;
}