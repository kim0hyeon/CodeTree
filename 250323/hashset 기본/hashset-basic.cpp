#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    unordered_set<int> s;

    for (int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        int a;
        cin >> a;

        if (cmd == "add")    
            s.insert(a);
        else if (cmd == "remove")
            s.erase(a);
        else
            s.find(a) != s.end() ? cout << "true" <<endl : cout << "false" << endl;
    }



    return 0;
}