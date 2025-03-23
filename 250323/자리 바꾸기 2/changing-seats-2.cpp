#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    // arr[i]는 현재 i번 좌석(0-indexed)에 앉아있는 사람(0-indexed)을 의미합니다.
    vector<int> arr(n);
    // 각 사람(0-indexed)이 앉은 좌석 번호(0-indexed)를 저장하는 unordered_set
    vector<unordered_set<int>> seats(n);
    
    // 초기 배치: 사람 i는 좌석 i에 앉아있음.
    for (int i = 0; i < n; i++){
        arr[i] = i;
        seats[i].insert(i); // 사람 i는 처음에 좌석 i에 앉았으므로
    }
    
    // k번의 swap 연산을 저장 (입력은 1-indexed)
    vector<pair<int, int>> swaps;
    swaps.reserve(k);
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        swaps.push_back({a, b});
    }
    
    // 총 3k번의 swap을 진행 (k번의 swap 연산을 3번 반복)
    int totalSwaps = 3 * k;
    for (int t = 0; t < totalSwaps; t++){
        // 현재 swap 연산 (1-indexed)
        int a = swaps[t % k].first;
        int b = swaps[t % k].second;
        // 0-indexed로 변환
        int indexA = a - 1;
        int indexB = b - 1;
        
        // 현재 좌석에 앉은 사람 (0-indexed)
        int personA = arr[indexA];
        int personB = arr[indexB];
        
        // swap 후, personA는 좌석 indexB, personB는 좌석 indexA에 앉게 됨.
        seats[personA].insert(indexB);
        seats[personB].insert(indexA);
        
        // 실제 배열 상에서 swap을 수행
        swap(arr[indexA], arr[indexB]);
    }
    
    // 각 사람별로 앉은 좌석의 개수를 출력 (문제에서 요구한 "몇 군데의 자리" 즉, 서로 다른 좌석의 수)
    for (int i = 0; i < n; i++){
        cout << seats[i].size() << "\n";
    }
    
    return 0;
}
