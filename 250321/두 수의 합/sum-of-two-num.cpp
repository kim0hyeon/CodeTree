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
        umap[num] += 1;
    }

    // 이렇게 풀면 시간 초과. 시간 복잡도를 줄일 방법이 필요한데. 맵을 만들 때 작업이 필요할것같은데...
    int answer = 0;
    for (auto &pair : umap){
        if (umap.find(m-pair.first) != umap.end()){
            answer += pair.second * umap[m-pair.first];
            umap[pair.first] = 0;
            umap[m-pair.first] = 0;
        }
    }

    cout << answer;

    return 0;
}

