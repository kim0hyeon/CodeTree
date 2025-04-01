#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<double, double>> v;
    for (int i = 0; i < n; i++){
        double weight, value;
        cin >> weight >> value;
        v.emplace_back(make_pair(value/weight, weight));
    }

    sort(v.begin(), v.end(), greater<pair<double,double>>());

    double ans = 0;

    for (auto pair : v){
        if (m-pair.second >= 0){
            ans += pair.first * pair.second;
            m -= pair.second;
        } else{
            ans += pair.first * m;
            break;
        }
    }

    cout << fixed << setprecision(3);
    cout << ans;
    return 0;
}