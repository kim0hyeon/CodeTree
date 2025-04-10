#include <iostream>
using namespace std;

int main() {
    int count = 0;
    for (int i = 0; i < 16; i++){
        int n; cin >> n;
        if (n % 5 == 0) count++;
    }

    cout << count;
    return 0;
}