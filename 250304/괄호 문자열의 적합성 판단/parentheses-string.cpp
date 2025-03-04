#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;  // char 타입으로 선언하는 것이 가독성에 좋습니다.

    for (char c : str){
        if (c == ')') {
            if (!s.empty() && s.top() == '(')
                s.pop();
            else {
                cout << "No";
                return 0;
            }
        } else {  // c가 '('인 경우
            s.push(c);
        }
    }

    if (s.empty())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
