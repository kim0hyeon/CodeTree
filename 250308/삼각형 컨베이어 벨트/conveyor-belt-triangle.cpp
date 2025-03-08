#include <iostream>

using namespace std;


int main(){
    int n, t;
    cin >> n >> t;
    int arr1[n], arr2[n], arr3[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    for (int i = 0; i < n; i++)
        cin >> arr3[i];

    while (t > 0){
        int tmp = arr1[n-1];
        for (int i = n; i >= 1; i--){
            arr1[i] = arr1[i-1];
        }
        
        arr1[0] = arr3[n-1];

        int tmp2 = arr2[n-1];

        for (int i = n; i >= 1; i--){
            arr2[i] = arr2[i-1];
        }

        arr2[0] = tmp;

        for (int i = n; i >= 1; i--){
            arr3[i] = arr3[i-1];
        }

        arr3[0] = tmp2;

        t--;
    }

    for (int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++){
        cout << arr2[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++){
        cout << arr3[i] << " ";
    }

    return 0;
}