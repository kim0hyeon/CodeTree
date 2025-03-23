#include <iostream>
#include <set>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;

        if (cmd == "add"){
            int a;
            cin >> a;
            s.insert(a);
        } else if (cmd == "remove"){
            int a;
            cin >> a;
            s.erase(a);
        } else if (cmd == "find"){
            int a;
            cin >> a;
            s.find(a) != s.end() ? cout << "true" << endl : cout << "false" << endl;
        } else if (cmd == "lower_bound"){
            int a;
            cin >> a;
            if (s.lower_bound(a) == s.end())
                cout << "None" << endl;
            else
                cout << *s.lower_bound(a) << endl;
        } else if (cmd == "upper_bound"){
            int a;
            cin >> a;
            if (s.upper_bound(a) == s.end())
                cout << "None" << endl;
            else
                cout << *s.upper_bound(a) << endl;
        } else if (cmd == "largest"){
            if (s.empty())
                cout << "None" << endl;
            else
                cout << *s.rbegin() << endl;
        } else if (cmd == "smallest"){
            if (s.empty())
                cout << "None" << endl;
            else
                cout << *s.begin() << endl;
        }
    }



    return 0;
}