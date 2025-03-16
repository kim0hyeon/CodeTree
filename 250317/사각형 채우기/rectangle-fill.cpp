#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> grid(n+1);

    grid[0] = 0;
    grid[1] = 1;
    grid[2] = 2;

    for (int i = 3; i <= n; i++){
        grid[i] = (grid[i-1] + grid[i-2]) % 10007;
    }

    cout << grid[n];


    return 0;
}

// 4일땐?
// 1,1,1,1 / 2,1,1 / 1,1,2 / 1,2,1 / 2,2