#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    string s;
    cin >> s;

    unordered_map<char, int> umap;

    for (char c : s){
        umap[c]++;
    }

    vector<pair<char, int>> vec;

    for (char c : s){
        if (umap[c] == 1){
            cout << c;
            return 0;
        }
    }

    cout << "None";

    return 0;
}