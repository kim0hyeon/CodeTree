#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(6);
    int a = 13;
    double b = 0.165;
    cout << a << " * " << b << " = " << a*b; 
    return 0;
}