#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }

    sort(v.begin(), v.end());

    int last = 0, count = 0;
    for (auto &pair : v){
        int start = pair.second, end = pair.first;
        
        if (last <= start){
            count++;
            last = end;
        }
    }

    cout << n-count;

    return 0;
}