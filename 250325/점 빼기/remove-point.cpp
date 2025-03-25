// pair을 이용한 set와 lower_bound 이용하기
#include <iostream>
#include <set>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;

        if (s.lower_bound(make_pair(x, 0)) == s.end()){  // 해당 x보다 더 큰 녀석이 존재하지 않을 경우
            cout << -1 << " " << -1 << endl;
            continue;
        }

        auto pos = *s.lower_bound(make_pair(x, 0));
        cout << pos.first << " " << pos.second << endl;
        s.erase(pos);
    }

    return 0;
}