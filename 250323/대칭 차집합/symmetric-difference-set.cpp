#include <iostream>
#include <unordered_set>

using namespace std;


int main(){
    int na, nb;
    cin >> na >> nb;

    unordered_set<int> a;
    unordered_set<int> b;
    for (int i = 0; i < na; i++){
        int n;
        cin >> n;
        a.insert(n);
    }
    for (int i = 0; i < nb; i++){
        int n;
        cin >> n;
        b.insert(n);
    }

    unordered_set<int> c;
    for (int num : a){
        if (b.find(num) == b.end())
            c.insert(num);
    }

    for (int num : b){
        if (a.find(num) == a.end())
            c.insert(num);
    }

    cout << c.size();

    return 0;
}