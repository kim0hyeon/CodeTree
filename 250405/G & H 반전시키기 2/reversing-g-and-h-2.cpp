#include <iostream>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;

    string origin, target;
    cin >> origin >> target;

    int count = 0;
    for (int i = n-1; i >= 0; i--){
        if (origin[i] != target[i]){
            for (int j = 0; j <= i; j++){
                origin[j] == 'G' ? origin[j] = 'H' : origin[j] = 'G';
            }
            count++;
        }
    }

    cout << count;

    return 0;
}