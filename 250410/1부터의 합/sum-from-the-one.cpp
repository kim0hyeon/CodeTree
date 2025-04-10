#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 0, answer;
    for (int i = 1; i <= 100; i++){
        total += i;
        if (total >= n){
            answer = i;
            break;
        }
    }

    cout << answer;

    return 0;
}