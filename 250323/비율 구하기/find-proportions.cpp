#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;


int main(){
    int n;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s]++;
    }

    cout << fixed << setprecision(4);
    for (auto &pair : m){
        cout << pair.first << " " << (double)pair.second*100/n << endl;
    }



    return 0;
}