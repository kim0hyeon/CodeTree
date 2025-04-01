#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    int max_val = INT_MIN;
    for (int num : arr){
        ans += num;
        max_val = max(max_val, ans);
        if (ans < 0){
            ans = 0;
        }
    }

    cout << max_val;
    return 0;
}