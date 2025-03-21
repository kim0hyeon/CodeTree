#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
    int n, m, num;
    cin >> n >> m;

    unordered_map<int, int> umap;


    for (int i = 0; i < n; i++){
        cin >> num;
        umap[num] += 1;
    }

    for (int i = 0; i < m; i++){
        cin >> num;
        if (umap.find(num) == umap.end()){
            cout << 0 << " ";
        } else{
            cout << umap[num] << " ";
        }
    }


    return 0;
}