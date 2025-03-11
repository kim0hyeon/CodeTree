#include <iostream>
#include <vector>

using namespace std;


bool upper(vector<int> &v){
    int idx = 0;
    while (v[idx] == 5){
        v[idx] = 1;
        idx++;
        if (idx == v.size()) return false;
        v[idx]++;
    }
    return true;
}

int check(vector<int> &v){
    int two = 0, three = 0, four = 0;
    bool flag = true;

    for (int num : v){
        if (num == 1){
            if ((two > 0 && two < 2) || (three > 0 && three < 3) || (four > 0 && four < 4)){
                flag = false;
                break;
            }
        } else if (num == 2){
            if ((three > 0 && three < 3) || (four > 0 && four < 4)){
                flag = false;
                break;
            }
            two = (two+1) % 2;
        } else if (num == 3){
            if ((two > 0 && two < 2) || (four > 0 && four < 4)){
                flag = false;
                break;
            }
            three = (three+1) % 3;
        } else{
            if ((two > 0 && two < 2) || (three > 0 && three < 3)){
                flag = false;
                break;
            }
            four = (four+1) % 4;
        }
    }

    if (two > 0 || three > 0 || four > 0) flag = false;

    if (!flag) return 0;
    return 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n, 1);

    int answer = 0;
    bool flag = true;

    while (flag){
        for (int j = 0; j < 4; j++){
            answer += check(v);
            v[0]++;

            if (j == 3){
                if(!upper(v)){
                    flag = false;
                    break;
                }
            }
            
        }
    }

    cout << answer;

    return 0;
}
