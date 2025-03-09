#include <iostream>
#include <string>

using namespace std;


string shift(string s){
    string result = "";
    
    for (int i = 1; i < s.length(); i++){
        result += s[i];
    }
    result += s[0];

    return result;
}

int check(string s){
    int total = 0;
    for (int i = 0; i < s.length()-1; i++){
        if (s[i] != s[i+1]) total += 2;
    }
    if (total == 0) return 3;
    return total;
}

int main(){
    string s;
    cin >> s;

    int max_val = 0;
    for (int i = 0; i < s.length(); i++){
        max_val = max(max_val, check(s));
        s = shift(s);
    }

    cout << max_val;

    return 0;
}