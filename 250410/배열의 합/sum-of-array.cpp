#include <iostream>
using namespace std;

int main() {

    for (int i = 0; i < 4; i++){
        int total = 0;
        for (int j = 0; j < 4; j++){
            int n; cin >> n; total += n;
        }
        cout << total << endl;
    }

    return 0;
}