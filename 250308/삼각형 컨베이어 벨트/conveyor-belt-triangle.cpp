#include <iostream>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    int arr1[n], arr2[n], arr3[n];

    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];
    for (int i = 0; i < n; i++) cin >> arr3[i];

    while (t > 0){
        int tmp1 = arr1[n-1];  // arr1 마지막 원소 저장
        int tmp2 = arr2[n-1];  // arr2 마지막 원소 저장
        int tmp3 = arr3[n-1];  // arr3 마지막 원소 저장

        // arr1 한 칸씩 이동
        for (int i = n-1; i > 0; i--){
            arr1[i] = arr1[i-1];
        }
        arr1[0] = tmp3;  // arr1의 처음 값은 arr3의 마지막 원소

        // arr2 한 칸씩 이동
        for (int i = n-1; i > 0; i--){
            arr2[i] = arr2[i-1];
        }
        arr2[0] = tmp1;  // arr2의 처음 값은 arr1의 마지막 원소

        // arr3 한 칸씩 이동
        for (int i = n-1; i > 0; i--){
            arr3[i] = arr3[i-1];
        }
        arr3[0] = tmp2;  // arr3의 처음 값은 arr2의 마지막 원소

        t--;
    }

    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";

    return 0;
}
