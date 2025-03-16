#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vec;

int main(){
    cin >> n;
    vec = vector<int>(n, -1);
    vec[0] = 1;
    vec[1] = 1;

    for (int i = 2; i < n; i++){
        vec[i] = vec[i-1] + vec[i-2];
    }

    cout << vec[n-1];

}