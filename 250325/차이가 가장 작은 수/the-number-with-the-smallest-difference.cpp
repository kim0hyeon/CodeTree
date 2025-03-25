// 가장 첫 원소부터 시작해서 lower_bound를 찾는다.
#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;


int main(){
    int n, m, num;
    set<int> s;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> num;
        s.insert(num);
    }

    int min_val = INT_MAX;
    auto it = s.begin();
    for (int i = 0; i < n; i++){
        auto itplus = s.lower_bound((*it)+m);

        if (itplus == s.end()){
            break;
        }

        min_val = min(min_val, *itplus - *it);
        it++;
    }

    min_val == INT_MAX ? cout << -1 : cout << min_val;

    return 0;
}