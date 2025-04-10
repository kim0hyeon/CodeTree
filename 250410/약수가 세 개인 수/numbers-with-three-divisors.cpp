#include <iostream>

using namespace std;



int main() {
    int start, end;
    cin >> start >> end;

    int answer = 0;
    for (int i = start; i <= end; i++){

        int count = 0;

        for (int j = 1; j <= i; j++){
            if (i%j == 0) count++;
        }

        if (count == 3) answer++;
    }

    cout << answer;

    return 0;
}
