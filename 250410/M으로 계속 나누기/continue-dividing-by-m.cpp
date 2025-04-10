#include <iostream>

using namespace std;

int main() {
    int n,m;

    cin >> n;
    cin >> m;
    
    while (n != 0){
        cout << n << endl;
        n = n/m;
    }
    
    return 0;
}
