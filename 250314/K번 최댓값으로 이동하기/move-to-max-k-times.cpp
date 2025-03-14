#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, k, start_num;
vector<vector<int>> grid;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
pair<int, int> min_position;

// 시작위치에서 전체 탐색 진행
// 시작 숫자보다 작으면서 가장 큰 녀석을 계속 체크
// 만약 이전 숫자와 같다면 행과 열 비교 행이 작은 녀석을 고르고 행이 같다면 열이 작은 녀석을 골라야 함
// 시작하자마자 아무데도 움직일 수 없는 경우도 생각해야 한다. 그럼 min_position에 값이 안 들어가게 되는데 
void BFS(){
    int max_num = 0;

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first, y = current.second;

        if (grid[x][y] > max_num && grid[x][y] < start_num){
            max_num = grid[x][y];
            min_position = make_pair(x, y);
        } 
        else if (grid[x][y] == max_num && grid[x][y] < start_num){
            if (min_position.first > x){
                min_position = make_pair(x, y);
            }
            else if (min_position.first == x && min_position.second > y){
                min_position = make_pair(x, y);
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        for (int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            if (tx > 0 && tx <= n && ty > 0 && ty <= n){
                if (grid[tx][ty] < start_num && !visited[tx][ty]){
                    q.push(make_pair(tx, ty));
                    visited[tx][ty] = true;
                }
            }
        }
    }

    // while문을 벗어났으면 다음 호출시 제대로 작동할 수 있게 q에 현재 min_position을 넣어주고, start_num을 변경하고, visited를 초기화한다.
    q.push(make_pair(min_position.first, min_position.second));
    start_num = max_num;
    visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
}

int main(){
    cin >> n >> k;
    grid = vector<vector<int>>(n+1, vector<int>(n+1));
    visited = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    start_num = grid[x][y];
    q.push(make_pair(x, y));
    visited[x][y] = true;
    min_position = make_pair(x, y);  // 시작하자마자 끝날 경우도 생각해서 min_position에 값을 넣어준다.


    for (int i = 0; i < k; i++)
        BFS();

    cout << min_position.first << " " << min_position.second << endl;
    return 0;
}

