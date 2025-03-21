#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> umap;

    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        umap[i] = num;
    }

    int answer = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (umap[i] + umap[j] == m) answer++;
        }
    }

    cout << answer;

    return 0;
}