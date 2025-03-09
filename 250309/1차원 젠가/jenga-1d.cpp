#include <iostream>
#include <vector>

using namespace std;


vector<int> remove(vector<int> vec, int start, int end){
    vector<int> ans;
    start--;
    end--;

    for (int i = 0; i < vec.size(); i++){
        if (i >= start && i <= end) continue;
        ans.push_back(vec[i]);
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int start, end;
    for (int i = 0; i < 2; i++){
        cin >> start >> end;
        vec = remove(vec, start, end);
    }

    cout << vec.size() << endl;
    for (int num : vec) cout << num << endl;


    return 0;
}