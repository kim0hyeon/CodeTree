#include <iostream>
#include <map>

using namespace std;


int main(){
    int n, a;
    map<int, int> m;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (m.find(a) == m.end()) m[a] = i+1;
    }

    for (auto &pair : m){
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}