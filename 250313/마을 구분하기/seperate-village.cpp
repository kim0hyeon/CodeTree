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

    if (x-1 >= 0 && grid[x-1][y] == 1 && !checked[x-1][y]){
        DFS_search(x-1, y);
    }
    if (y-1 >= 0 && grid[x][y-1] == 1 && !checked[x][y-1]){
        DFS_search(x, y-1);
    }
    if (x+1 < n && grid[x+1][y] == 1 && !checked[x+1][y]){
        DFS_search(x+1, y);
    }
    if (y+1 < n && grid[x][y+1] == 1 && !checked[x][y+1]){
        DFS_search(x, y+1);
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