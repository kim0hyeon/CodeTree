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

        // num보다 큰 첫 번째 원소를 찾는다.
        auto it = s.upper_bound(num);
        // num 이하의 원소가 없으면 종료
        if(it == s.begin()){
            cout << answer;
            return 0;
        }
        // it를 감소시켜 num 이하의 가장 큰 원소로 만든다.
        --it;
        answer++;
        s.erase(it);
    }

    cout << answer;
    return 0;
}
