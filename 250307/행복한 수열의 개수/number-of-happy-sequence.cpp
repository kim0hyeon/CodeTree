#include <iostream>
#include <vector>
using namespace std;


bool check_row(vector<vector<int>> &grid, int x, int y, int m){
    if (grid.size() < y+m){ // 가로의 범위를 벗어난다면 측정할 수 없으니 false리턴
        return false;
    }

    int start_n = grid[x][y];
    for (int i = y+1; i < y+m; i++){
        if (start_n != grid[x][i]){
            return false;
        }
    }

    return true;
}

bool check_col(vector<vector<int>> &grid, int x, int y, int m){
    if (grid.size() < x+m){
        return false;
    }

    int start_n = grid[x][y];
    for (int i = x+1; i < x+m; i++){
        if (start_n != grid[i][y]){
            return false;
        }
    }

    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (check_row(grid, i, j, m)){ // 해당 행은 true이므로 다음으로 넘어감
                answer++;
                break;
            }
        }
    }

    for (int j = 0; j < n; j++){
        for (int i = 0; i < n; i++){
            if (check_col(grid, i, j, m)){ // 해당 열은 true이므로 다음으로 넘어감
                answer++;
                break;
            }
        }
    }

    cout << answer;
    
    return 0;
}