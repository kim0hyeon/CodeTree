#include <iostream>
#include <string>

using namespace std;

int main() {
    char c;
    cin >> c;

    string arr[5] = {"apple", "banana", "grape", "blueberry", "orange"};

    int count = 0;

    for (int i = 0; i < 5; i++){
        if (arr[i][2] == c || arr[i][3] == c){
            count++;
            cout << arr[i] << endl;
        }
    }

    cout << count;

    return 0;
}