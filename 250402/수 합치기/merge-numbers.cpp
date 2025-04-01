#include <iostream>
#include <set> // 생각해보니까 얘는 중복이 안되네.

using namespace std;


int main(){
    int n;
    cin >> n;
    multiset<int> s;
    
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        s.insert(a);
    }

    int ans = 0;

    while (s.size() > 1){
        int a = *s.begin();
        s.erase(s.begin());
        int b = *s.begin();
        s.erase(s.begin());

        ans += (a + b);
        s.insert(a+b);
    }

    cout << ans;

    return 0;
}