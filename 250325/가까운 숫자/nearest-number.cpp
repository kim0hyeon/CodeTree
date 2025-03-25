#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n, x;
    cin >> n; // n 입력 추가
    set<int> s;
    
    s.insert(0); // 처음 0 위치 점 추가
    
    // 첫 번째 점 처리
    cin >> x;
    s.insert(x);
    int min_val = abs(x - 0);
    cout << min_val << "\n";
    
    // 남은 점들에 대해 처리
    for (int i = 1; i < n; i++){
        cin >> x;
        s.insert(x);
        auto it = s.find(x);
        
        // 오른쪽 이웃 검사 (존재하면)
        if(next(it) != s.end()){
            min_val = min(min_val, abs(*next(it) - x));
        }
        
        // 왼쪽 이웃 검사 (존재하면)
        if(it != s.begin()){
            auto prev_it = it;
            prev_it--;
            min_val = min(min_val, abs(x - *prev_it));
        }
        
        cout << min_val << "\n";
    }
    
    return 0;
}
