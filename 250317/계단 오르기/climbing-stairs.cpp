#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> step(n+1, 0);

    step[2] = 1;
    step[3] = 1;

    for (int i = 4; i <= n; i++){
        step[i] = step[i-2] + step[i-3];
    }

    cout << step[n];
}