#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    unordered_map<int, long long> freq;
    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        freq[num]++;
    }
    
    long long answer = 0;
    for(auto &p : freq){
        int x = p.first;
        int y = m - x;
        if(freq.find(y) != freq.end()){
            if(x == y){
                // 같은 숫자일 경우, 조합으로 계산
                answer += p.second * (p.second - 1LL) / 2;
            }
            else if(x < y){ // 중복 계산 방지
                answer += p.second * freq[y];
            }
        }
    }
    
    cout << answer;
    return 0;
}