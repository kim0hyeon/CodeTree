#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[100000];

void RadixSort(){
    int p = 1;
    for (int pos = 0; pos < 6; pos++){
        vector<int> arr_new[10];
        for (int i = 0; i < n; i++){
            int digit = (arr[i] / p) % 10;
            arr_new[digit].push_back(arr[i]);
        }

        int index = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < (int)arr_new[i].size(); j++){
                arr[index++] = arr_new[i][j];
            }
        }
    
        p *= 10;
    }
}

int main() {
    
    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    RadixSort();

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
