#include <iostream>

using namespace std;


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

        int idx = lowerbound(arr, target, n-1);

        if (arr[idx] == target) cout << idx+1 << endl;
        else cout << -1 << endl;
    }




}