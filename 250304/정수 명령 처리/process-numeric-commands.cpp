#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v;
    
    for (int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;

        if (cmd == "push"){
            int num;
            cin >> num;
            v.push_back(num);
        } else if (cmd == "pop"){
            cout << v.back() << endl;
            v.pop_back();
        } else if (cmd == "size"){
            cout << v.size() << endl;
        } else if (cmd == "empty"){
            if (v.size() == 0) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (cmd == "top"){
            cout << v.back() << endl;
        }
    }


    return 0;
}