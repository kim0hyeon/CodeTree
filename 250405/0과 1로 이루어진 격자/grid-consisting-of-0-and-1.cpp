#include <iostream>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; i++){
        string num;
        cin >> num;
        for (int j = 0; j < n; j++){
            arr[i][j] = num[j]-'0';
        }
    }

    int count = 0;
    for (int i = n-1; i >= 0; i--){
        for (int j = n-1; j >= 0; j--){
            if (arr[i][j] == 1){
                count++;
                for (int x = 0; x <= i; x++){
                    for (int y = 0; y <= j; y++){
                        arr[x][y] = (arr[x][y]+1) % 2;
                    }
                }
            }
        }
    }


    cout << count;

    return 0;
}