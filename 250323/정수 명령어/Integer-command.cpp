#include <iostream>
#include <set>

using namespace std;


int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        set<int> s;

        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            int num;
            cin >> num;

            if (c == 'I'){
                s.insert(num);
            } else if (num == 1 && !s.empty()){
                s.erase(*s.rbegin());
            } else if (num == -1 && !s.empty()){
                s.erase(*s.begin());
            }
        }

        s.empty() ? cout << "EMPTY" << endl : cout << *s.rbegin() << " " << *s.begin() << endl;
    }
    return 0;
}