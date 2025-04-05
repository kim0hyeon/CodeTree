// 이전 값이 1이면 다음 칸은 하면 안된다. 다음 다음부터 가능
#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;
    for (int i = 1; i < n; i++){
        if (arr[i-1] == 0){
            arr[i-1] = 1;
            arr[i] = (arr[i]+1) % 2;
            arr[i+1] = (arr[i+1]+1) % 2;
            count++;
        }
    }

    bool complete = true;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            complete = false;
            break;
        }
    }

    if (complete) cout << count;
    else cout << -1;


    return 0;
}