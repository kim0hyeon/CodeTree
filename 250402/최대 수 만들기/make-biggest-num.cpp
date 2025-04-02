#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


bool cmp(int a, int b){
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return ab > ba;
}   

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, cmp);

    for (int a : arr)
        cout << a;

    return 0;
}