#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> vec;
    vector<int> reward(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++){
        int start, end, money;
        cin >> start >> end >> money;

        // 알바가 시작되는 날짜가 증가하는 순으로 데이터가 주어지므로 들어오는대로 저장한다.
        vec.push_back(make_pair(start, end));
        reward.push_back(money);
        dp.push_back(money);  // 해당 인덱스에선 자기 자신은 반드시 깔고 간다고 생각해야한다.
    }

    for (int i = 0; i < n; i++){
        int current_start = vec[i].first;

        for (int j = 0; j < i; j++){
            int front_end = vec[j].second;
            if (front_end < current_start){
                dp[i] = max(dp[i], dp[j] + reward[i]);
            }

        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}

// pair로 시작과 끝 부분을 저장해놓고
// 앞에서부터 뒤로 가면서 최대값을 저장한다.
// 만약 앞의 녀석의 마지막 값보다 내 시작 값이 크다면 알바를 추가할 수 있다. 그렇게 추가한 것과 내 코스트를 비교해 더 큰 녀석을 고르면 된다.