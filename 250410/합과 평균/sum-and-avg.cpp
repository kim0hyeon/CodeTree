#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << fixed << setprecision(1);

    cout << a + b << " " << (double)(a+b)/2;

    return 0;
}