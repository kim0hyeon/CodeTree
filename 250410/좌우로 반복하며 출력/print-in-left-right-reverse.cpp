#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 1; i <= n; i++) arr[i-1] = i;

    for (int i = 0; i < n; i++){
        if (i%2 == 0){
            for (int j = 0; j < n; j++)
                cout << arr[j];
        } else{
            for (int j = n-1; j >= 0; j--)
                cout << arr[j];
        }
        cout << endl;
    }

    return 0;
}