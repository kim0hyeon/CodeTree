#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    unordered_map<string, int> umap;

    for (int i = 0; i < n; i++){
        cin >> s;
        umap[s]++;
    }

    int max_val = 0;
    for (auto pair : umap){
        if (pair.second > max_val) max_val = pair.second;
    }

    cout << max_val;

    return 0;
}