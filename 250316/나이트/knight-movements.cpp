#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<bool>> visited;
vector<vector<int>> step;
queue<pair<int, int>> q;

void BFS(){
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        int cur_step = step[x][y];

        int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

        for (int i = 0; i < 8; i++){
            int tx = x + dx[i], ty = y + dy[i];

            if (tx > 0 && tx <= n && ty > 0 && ty <= n){
                if (!visited[tx][ty]){
                    step[tx][ty] = cur_step + 1;
                    visited[tx][ty] = true;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
}

int main(){
    cin >> n;
    visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
    step = vector<vector<int>>(n+1, vector<int>(n+1, -1));

    int x1, y1;
    cin >> x1 >> y1;
    q.push(make_pair(x1, y1));
    visited[x1][y1] = true;
    step[x1][y1] = 0;

    BFS();

    int x2, y2;
    cin >> x2 >> y2;

    cout << step[x2][y2];

    return 0;
}