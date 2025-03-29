#include <iostream>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < m; i++){
        int target, idx = -1,left = 0, right = n-1;
        cin >> target;

        while (left <= right){
            int mid = (left + right) / 2;
            
            if (arr[mid] == target){
                idx = mid+1;
                break;
            }
            
            if (arr[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }

        cout << idx << endl;
    }


    return 0;
}