// 필요한 함수: choose함수, 고르는게 가능한지 확인하는 check함수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
int ans = 0;
vector<int> lines;
vector<int> l;
vector<int> r;

bool isPossible(int idx){
    for (int i = 0; i < lines.size(); i++){
        int ori_left = l[lines[i]];
        int ori_right = r[lines[i]];
        int new_left = l[idx];
        int new_right = r[idx];

        // 새로운 선이 들어가는 게 불가능한 경우
        if (!(ori_left > new_right || ori_right < new_left)){
            return false;
        }
    }
    return true;
}

void Check(int idx){
    if (idx == n){
        ans = max(ans, (int)lines.size());
        return ;
    }

    if (isPossible(idx)){
        lines.push_back(idx);
        Check(idx+1);
        lines.pop_back();
    }
    Check(idx+1);
}

int main(){
    cin >> n;
    l = vector<int>(n, 0);
    r = vector<int>(n, 0);

    for (int i = 0; i < n; i++){
        cin >> l[i];
        cin >> r[i];
    }

    Check(0);
    cout << ans;
    return 0;
}