#include <iostream>
#include <unordered_set>

using namespace std;


int main(){
    int n;
    cin >> n;

    unordered_set<int> s;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    cout << s.size();

    return 0;
}