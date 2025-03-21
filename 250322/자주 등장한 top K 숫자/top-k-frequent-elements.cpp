#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // 각 숫자의 등장 횟수를 계산합니다.
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    
    // freq map을 (숫자, 등장 횟수) pair의 vector로 변환합니다.
    vector<pair<int, int>> vec;
    for (auto &entry : freq) {
        vec.push_back({entry.first, entry.second});
    }
    
    // 정렬: 등장 횟수가 내림차순, 등장 횟수가 같다면 숫자 값이 내림차순.
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    });
    
    // 상위 k개의 숫자 출력 (공백으로 구분)
    for (int i = 0; i < k && i < vec.size(); i++){
        cout << vec[i].first << " ";
    }
    
    return 0;
}
