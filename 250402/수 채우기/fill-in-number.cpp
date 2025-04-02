#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;

    int ans = 0;

    if (n == 1 || n == 3){
        cout << -1;
    } else if (n % 2 == 0){
        ans += n/5;
        n = n%5;
        ans += n/2;
    } else {
        ans += n/5 - 1;
        n = n%5 + 5;
        ans += n/2;
    }

    cout << ans;

    return 0;
}