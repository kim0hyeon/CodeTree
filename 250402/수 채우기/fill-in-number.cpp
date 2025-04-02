#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    if (n == 1){
        cout << -1;
        return 0;
    }

    int ans = 0;
    ans += n/5;
    n %= 5;

    ans += n/2;
    n %= 2;

    while (n > 0) {
        ans -= 1;
        n += 5;
        ans += n/2;
        n %= 2;
    }

    cout << ans;

    return 0;
}