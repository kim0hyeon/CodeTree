#include <iostream>
#include <queue>
#include <tuple>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pq.push(make_tuple(-(x+y), -x, -y));
    }

    for (int i = 0; i < m; i++){
        auto top = pq.top();
        pq.pop();
        pq.push(make_tuple(get<0>(top)-4, get<1>(top)-2, get<2>(top)-2));
    }

    auto top = pq.top();
    cout << -get<1>(top) << " " << -get<2>(top);

    return 0;
}