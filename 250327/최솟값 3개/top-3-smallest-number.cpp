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
        q.push(-a);

        if (q.size() >= 3){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int c = q.top();
            
            cout << -a * b * c << endl;

            q.push(a);
            q.push(b);
        } else{
            cout << -1 << endl;
        }
    }



    return 0;
}