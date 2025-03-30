#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long s;
    cin >> s;

    long long max_num = 1;
    long long left = 1, right = s;
    while (left <= right){
        long long mid = (left + right) / 2;

        if (mid > 2 * s / (mid+1)){
            right = mid-1;
        } else{
            max_num = max(max_num, mid);
            left = mid+1;
        }
    }

    cout << max_num;
    return 0;
}