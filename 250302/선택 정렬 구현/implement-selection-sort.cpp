#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min, tmp;
    for (int i = 0; i < n; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        if (min != i){
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
