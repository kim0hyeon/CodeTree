#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int k, n;
    cin >> n >> k;

    set<int> s;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    vector<int> answer(s.begin(), s.end());
    sort(answer.begin(), answer.end(), greater<int>());

    for (int i = 0; i < k; i++)
        cout << answer[i] << " ";

    return 0;
}