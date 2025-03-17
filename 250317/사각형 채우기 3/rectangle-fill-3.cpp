#include <iostream>
using namespace std;

long long MOD = 1000000007;

int main(){
    int n;
    cin >> n;

    // n이 0 또는 1인 경우를 미리 처리
    if(n == 0) {
        cout << 1; 
        return 0;
    }
    if(n == 1) {
        cout << 2; 
        return 0;
    }

    long long arr[n+1];
    arr[0] = 1; // 2x0 보드: 빈 타일링 1가지
    arr[1] = 2; // 2x1 보드: 2가지 방법
    arr[2] = 7; // 2x2 보드: 7가지 방법 (문제에서 주어진 값)
    arr[3] = 22;

    for (int i = 4; i <= n; i++){
        arr[i] = ((arr[i-1] * 2 + arr[i-2] * 3 + arr[i-3] * 2 - arr[i-4]) % MOD + MOD) % MOD;

    }

    cout << arr[n];

    return 0;
}
