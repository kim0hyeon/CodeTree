#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            m[i*j] += 1;
        }
    }

    vector<int> vec;
    for (auto &pair : m){
        for (int i = 0; i < pair.second; i++){
            vec.push_back(pair.first);
        }
    }

    cout << vec[k-1];

    return 0;
}