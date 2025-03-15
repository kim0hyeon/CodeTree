#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k, u, d, counts;
vector<vector<int>> grid;
vector<vector<bool>> visited;
queue<pair<int, int>> q;


bool CanGo(int x, int y, int start_num){
    if (x > 0 && x <= n && y > 0 && y <= n){
        if (abs(start_num-grid[x][y]) >= u && abs(start_num-grid[x][y]) <= d && !visited[x][y]){
            return true;
        } else{
            return false;
        }
    }
    return false;
}

void BFS(){
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        int start_num = grid[x][y];
        counts++;  // 방문한 나라 +1

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for (int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (CanGo(tx, ty, start_num)){
                q.push(make_pair(tx, ty));
                visited[tx][ty] = true;
            }
        }
    }
}

int main(){
    cin >> n >> k >> u >> d;
    grid = vector<vector<int>>(n+1, vector<int>(n+1));
    visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    int max_val = 0;
    
    if (k == 1){
        for (int x = 1; x <= n; x++){
            for (int y = 1; y <= n; y++){
                counts = 0;
                q.push(make_pair(x,y));
                visited[x][y] = true;
                BFS();
                max_val = max(max_val, counts);
                visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
            }
        }
    }
    else if (k == 2){
        for (int x1 = 1; x1 <= n; x1++){
            for (int y1 = 1; y1 <= n; y1++){
                for (int x2 = x1; x2 <= n; x2++){
                    for (int y2 = y1; y2 <= n; y2++){
                        if (x1 == x2 && y1 == y2) continue;
                        
                        counts = 0;
                        q.push(make_pair(x1, y1));
                        visited[x1][y1] = true;
                        q.push(make_pair(x2, y2));
                        visited[x2][y2] = true;
                        BFS();
                        max_val = max(max_val, counts);
                        visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
                    }
                }
            }
        }
    }
    else if (k == 3){
        for (int x1 = 1; x1 <= n; x1++){
            for (int y1 = 1; y1 <= n; y1++){
                for (int x2 = x1; x2 <= n; x2++){
                    for (int y2 = y1; y2 <= n; y2++){
                        for (int x3 = x2; x3 <= n; x3++){
                            for (int y3 = y2; y3 <= n; y3++){
                                if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3)) continue;

                                counts = 0;
                                q.push(make_pair(x1, y1));
                                visited[x1][y1] = true;
                                q.push(make_pair(x2, y2));
                                visited[x2][y2] = true;
                                q.push(make_pair(x3, y3));
                                visited[x3][y3] = true;
                                BFS();
                                max_val = max(max_val, counts);
                                visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max_val;

    return 0;
}

// k가 될 수 있는 것은 1, 2, 3뿐이다.
// k가 1일때, k가 2일때, k가 3일때 경우를 따로 생각하는게 좋을것같은데?