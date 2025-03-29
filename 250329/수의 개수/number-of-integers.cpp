#include <iostream>
#include <algorithm>

using namespace std;

int upperbound(int arr[], int target, int right){
    int idx = right+1, left = 0;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] > target){  // arr[mid]가 target보다 더 커야 성립한다.
            right = mid-1;
            idx = min(idx, mid);
        } else{
            left = mid+1;
        }
    }

    return idx;
}

int lowerbound(int arr[], int target, int right){
    int idx = right+1, left = 0;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] >= target){
            right = mid-1;
            idx = min(idx, mid);
        } else{
            left = mid+1;
        }
    }

    return idx;
}

int main(){
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < m; i++){
        int target;
        cin >> target;

        cout << upperbound(arr, target, n-1) - lowerbound(arr, target, n-1) << endl;
    }


    return 0;
}