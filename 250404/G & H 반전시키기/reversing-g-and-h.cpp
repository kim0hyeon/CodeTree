#include <iostream>
#include <string>

using namespace std;


int main(){
    int n;
    string basic, result;
    cin >> n >> basic >> result;

    int count = 0;  // 문자열이 몇 개인지 세기 위한 변수
    bool diff = false;
    for (int i = 0; i < n; i++){
        if (basic[i] != result[i] && !diff){  // diff가 
            diff = true;
            count++;
        } else if (basic[i] == result[i]){
            diff = false;
        }
    }

    cout << count;

    return 0;
}