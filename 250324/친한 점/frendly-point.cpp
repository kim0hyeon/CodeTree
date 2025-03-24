#include <iostream>
#include <set>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> position;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        position.insert(make_pair(x, y));
    }

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        
        if (position.lower_bound(make_pair(x, y)) != position.end()){
            pair<int, int> tmp = *position.lower_bound(make_pair(x, y));
            cout << tmp.first << " " << tmp.second << endl;
        } else{
            cout << -1 << " " << -1 << endl;
        }
    }

    return 0;
}