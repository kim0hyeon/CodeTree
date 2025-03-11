#include <iostream>
#include <vector>

using namespace std;


void f(vector<int> &vec, vector<int> tmp, int n){
    if (n == 0){
        for (int t : tmp) cout << t << " ";
        cout << endl;
        return;
    }
    
    for (int i = 0; i < vec.size(); i++){
        tmp[tmp.size()-n] = vec[i];
        f(vec, tmp, n-1);
    }
}
    

int main(){
    int k, n;
    cin >> k >> n;

    vector<int> vec(k);
    vector<int> tmp(n);
    for (int i = 1; i <= k; i++) vec[i-1] = i;

    f(vec, tmp, n);

    return 0;
}