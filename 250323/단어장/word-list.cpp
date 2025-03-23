#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(){
    int n;
    map<string, int> m;
    cin >> n;

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s]++;
    }

    for (auto &pair : m)
        cout << pair.first << " " << pair.second << endl;

    return 0;
}