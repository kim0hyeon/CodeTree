#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;
    unordered_map<int, int> m;

    while (n-- > 0){
        string cmd;
        int a, b;

        cin >> cmd >> a;

        if (cmd == "add"){
            cin >> b;
            m[a] = b;
        } else if (cmd == "remove"){
            m.erase(a);
        } else{
            if (m.find(a) != m.end()){
                cout << m[a] << endl;
            } else{
                cout << "None" << endl;
            }
        }
    }



    return 0;
}