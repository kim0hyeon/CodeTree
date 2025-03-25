// 벡터 안에 set을 넣는다면 -> 그럼 1번을 풀 때 s.begin()과 s.rbegin()을 사용할 수 없어 -> 그래서 새로운 set을 만들면 될거야.
// 그럼 vector는 모든 녀석들이 들어갈 수 있게끔 엄청 크게 설정해놔야겠네.

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<set<int>> problems(101);
    set<int> levels;

    for (int i = 0; i < n; i++){
        int p, l;
        cin >> p >> l;

        levels.insert(l);
        problems[l].insert(p);
    }

    cin >> n;
    for (int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;

        if (cmd == "rc"){
            int x;
            cin >> x;

            if (x == 1){
                cout << *problems[*levels.rbegin()].rbegin() << endl;
            } else{
                cout << *problems[*levels.begin()].begin() << endl;
            }
        } else if (cmd == "ad"){
            int p, l;
            cin >> p >> l;

            levels.insert(l);
            problems[l].insert(p);
        } else if (cmd == "sv"){
            int p, l;
            cin >> p >> l;

            problems[l].erase(p);
            if (problems[l].size() == 0) levels.erase(l);
        }
    }

    return 0;
}