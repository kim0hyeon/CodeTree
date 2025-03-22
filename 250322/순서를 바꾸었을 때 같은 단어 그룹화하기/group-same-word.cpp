#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    unordered_map<string, int> groupCount;
    int maxCount = 0;
    
    for (int i = 0; i < n; i++){
        string word;
        cin >> word;
        
        // 단어의 문자들을 정렬하면 anagram 그룹의 대표값이 됩니다.
        string key = word;
        sort(key.begin(), key.end());
        
        // 해당 그룹의 단어 수 증가
        groupCount[key]++;
        if(groupCount[key] > maxCount)
            maxCount = groupCount[key];
    }
    
    cout << maxCount;
    return 0;
}
