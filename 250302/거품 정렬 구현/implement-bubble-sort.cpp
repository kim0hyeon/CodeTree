#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tmp;
    bool sorted;
    
    do {
        sorted = true;
        for (int i = 0; i < n-1; i++){
            if (arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                sorted = false;
            }
        }
    } while (!sorted);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
