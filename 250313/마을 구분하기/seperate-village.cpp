#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, cnt;
vector<vector<int>> grid;
vector<vector<bool>> checked;
vector<int> answer;


void DFS_search(int x, int y){
    cnt++;  // 집 하나 확인했으니 count++
    checked[x][y] = true;  // 방문했으니까 1로 변경

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,1,-1};

    for (int i = 0; i < 4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n){
            if (grid[tx][ty] == 1 && !checked[tx][ty])
                DFS_search(tx, ty);
        }
    }
}

int main(){
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n));
    checked = vector<vector<bool>>(n, vector<bool>(n, false));  // 확인하지 않은 부분은 false

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 1 && !checked[i][j]){
                cnt = 0;
                DFS_search(i, j);
                answer.push_back(cnt);
            }
        }
    }

    cout << answer.size() << endl;
    sort(answer.begin(), answer.end());
    for (auto num : answer){
        cout << num << endl;
    }

    return 0;
}