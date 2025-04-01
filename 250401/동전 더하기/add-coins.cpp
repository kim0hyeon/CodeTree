#include <iostream>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int answer = 0;

    for (int i = n-1; i >= 0; i--){
        if (k >= arr[i]){
            answer += k / arr[i];
            k %= arr[i];
            i++;
        }
    }

    cout << answer;

    return 0;
}