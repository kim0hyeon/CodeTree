#include <iostream>
#include <set>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    set<int> s;

    int num;

    for (int i = 0; i < n; i++){
        cin >> num;
        s.insert(num);
    }

    for (int i = 0; i < m; i++){
        cin >> num;

        if (s.lower_bound(num) != s.end()){
            cout << *s.lower_bound(num) << endl;
        } else{
            cout << -1 << endl;
        }
    }



    return 0;
}