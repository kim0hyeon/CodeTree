#include <iostream>

using namespace std;


int main(){
    int n, t;
    cin >> n >> t;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    while (t > 0){
        int tmp = arr1[n-1];
        for (int i = n; i >= 1; i--){
            arr1[i] = arr1[i-1];
        }
        
        arr1[0] = arr2[n-1];

        for (int i = n; i >= 1; i--){
            arr2[i] = arr2[i-1];
        }

        arr2[0] = tmp;

        t--;
    }

    for (int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++){
        cout << arr2[i] << " ";
    }


    return 0;
}