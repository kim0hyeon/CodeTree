#include <iostream>
using namespace std;

int main() {
    int answer_3 = 0, answer_5 = 0;

    for (int i = 0; i < 10; i++){
        int n;
        cin >> n;

        if (n%3 == 0) answer_3++;
        if (n%5 == 0) answer_5++;
    }

    cout << answer_3 << " " << answer_5;

    return 0;
}