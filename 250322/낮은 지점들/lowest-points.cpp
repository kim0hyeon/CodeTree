#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        if (m.find(x) != m.end()){
            m[x] = min(m[x], y);
        } else{
            m[x] = y;
        }
    }

    int answer = 0;
    for (auto &dot : m){
        answer += dot.second;
    }

    cout << answer;

    return 0;
}