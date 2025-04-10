#include <iostream>
using namespace std;

int main() {
    
    int total = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int n; cin >> n;
            if (j <= i) total += n;
        }
    }
    cout << total;

    return 0;
}