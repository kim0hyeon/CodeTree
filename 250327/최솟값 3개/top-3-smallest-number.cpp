#include <iostream>
#include <queue>

using namespace std;


int main(){
    int n;
    cin >> n;
    priority_queue<int> q;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);

        if (q.size() == 4) q.pop();  // q에 원소가 4개가 된 경우 최대원소 1개를 뺀다.

        if (q.size() == 3){
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            long long c = q.top();
            q.push(a);
            q.push(b);
            long long result = a * b * c;
            cout << result << endl;
        } else{
            cout << -1 << endl;
            continue;
        }

    }



    return 0;
}