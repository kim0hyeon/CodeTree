#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(){
    int n;
    map<int, int> m;

    cin >> n;

    for (int i = 0; i < n; i++){
        string cmd;
        int a, b;
        cin >> cmd;

        if (cmd == "add"){
            cin >> a >> b;
            m[a] = b;
        }
        else if (cmd == "find"){
            cin >> a;
            if (m.find(a) != m.end())
                cout << m[a] << endl;
            else
                cout << "None" << endl;
        }
        else if (cmd == "remove"){
            cin >> a;
            m.erase(a);
        }
        else{
            if (m.empty()) cout << "None" << endl;
            else{
                for (auto &pair : m){
                    cout << pair.second << " ";
                }
                cout << endl;
            }
        }
    }


    return 0;
}