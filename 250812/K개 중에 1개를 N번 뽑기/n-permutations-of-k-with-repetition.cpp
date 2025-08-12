#include <iostream>
#include <vector>

using namespace std;


int k, n;
vector<int> answer;

void PirntAnswer(){
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}

void Choose(int curr_num){
    if (curr_num == n+1){
        PirntAnswer();
        return ;
    }

    for (int i = 1; i <= k; i++){
        answer.push_back(i);  // 먼저 넣어보고
        Choose(curr_num+1);  // 다음 자리 숫자를 넣고
        answer.pop_back();  // 넣었던 0을 뺀다.
    }
    return ;
}

int main(){
    cin >> k >> n;
    Choose(1);
    return 0;
}