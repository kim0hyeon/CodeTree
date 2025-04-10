#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 0) cout << "ice";
    else if (n >= 100) cout << "viper";
    else cout << "water";
    return 0;
}