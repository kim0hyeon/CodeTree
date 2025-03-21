#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long ans = 0;
    unordered_map<int, long long> pairSum;
    // j가 현재 인덱스, arr[j]를 세 번째 원소로 사용한다고 생각합니다.
    for (int j = 0; j < n; j++) {
        // 지금까지 저장한 두 수의 합 중, k - arr[j]가 있다면 그것이 조건에 맞는 조합입니다.
        ans += pairSum[k - arr[j]];
        
        // 이후, j번째 원소와 이전 원소들을 짝지어 새로운 두 수의 합을 만듭니다.
        for (int i = 0; i < j; i++) {
            pairSum[arr[i] + arr[j]]++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
