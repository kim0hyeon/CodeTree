#include <iostream>
#include <vector>

using namespace std;

int n, total = 0;
vector<int> answer;

// 아름다운 수 인지 체크하는 함수
int isBeautiful(){
    int idx = 0;
    
    while (idx < n){
        int num = answer[idx];

        for (int i = idx+1; i < idx+num; i++){
            if (i >= n || answer[i] != num) return 0;
        }
        
        idx += num;
    }

    return 1;
}

// 모든 경우의 수를 구하는 함수
void Choose(int curr_num){
    if (curr_num == n+1){
        total += isBeautiful();
        return ;
    }

    for (int i = 1; i <= 4; i++){
        answer.push_back(i);
        Choose(curr_num+1);
        answer.pop_back();
    }
}

int main(){
    cin >> n;
    Choose(1);

    cout << total;
    return 0;
}