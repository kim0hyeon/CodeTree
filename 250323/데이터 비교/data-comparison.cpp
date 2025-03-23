#include <iostream>
#include <unordered_set>

using namespace std;


int main(){
    int n1;
    unordered_set<int> s1;

    cin >> n1;
    for (int i = 0; i < n1; i++){
        int a;
        cin >> a;
        s1.insert(a);
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++){
        int a;
        cin >> a;
        if (s1.find(a) == s1.end()) cout << 0 << " ";
        else cout << 1 << " ";
    }



    return 0;
}