#include <iostream>
#include <set>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    set<int> s;
    for (int i = 1; i <= m; i++)
        s.insert(i);

    int answer = 0, s_min = 1;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        for (int j = num; j >= 1; j--){
            if (s.find(j) != s.end()){
                answer++;
                if (j == s_min){
                    auto it = s.find(j);
                    s_min = *(it++);
                }
                s.erase(j);
                break;
            }
            if (j == 1 || j < s_min){
                cout << answer;
                return 0;
            }
        }
    }

    cout << answer;

    return 0;
}