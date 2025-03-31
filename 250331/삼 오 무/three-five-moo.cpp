#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    // 1~15 중 3,5의 배수가 아닌 수들 (오름차순)
    static const vector<long long> valid = {1,2,4,7,8,11,13,14};

    // 몇 번째 블록인지 (0-based)
    // (N-1)개를 8로 나눈 몫이 곧 블록 수, 나머지가 인덱스
    long long block = (N - 1) / 8; 
    long long r = (N - 1) % 8;

    long long answer = 15LL * block + valid[r];
    cout << answer << "\n";

    return 0;
}