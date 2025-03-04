#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
    string str;
    cin >> str;

    stack<int> s;

    for (char c : str){
        if (s.empty() == true && c == ')'){
            s.push(c);
            cout << "No";
            break;
        }
        else if (c == ')' && s.top() == '('){
            s.pop();
        } else{
            s.push(c);
        }
    }

    if (s.empty() == true) cout << "Yes";
    else cout << "No";


    return 0;
}
