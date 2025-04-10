#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][n];
    for (int j = 0; j < n; j++){
        for (int i = 0; i < n; i++){
            if (j%2 == 0) arr[i][j] = i+1;
            else arr[i][j] = n-i;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}