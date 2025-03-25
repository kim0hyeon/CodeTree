#include <iostream>
#include <set>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    set<int> s;
    for (int i = 1; i <= m; i++)
        s.insert(i);

    int answer = 0;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        for (int j = num; j >= 1; j--){
            if (s.find(j) != s.end()){
                answer++;
                s.erase(j);
                break;
            }
            if (j == 1){
                cout << answer;
                return 0;
            }
        }
    }

    cout << answer;

    return 0;
}