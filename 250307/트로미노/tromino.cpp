#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int check_rightangle(vector<vector<int>> &grid, int x, int y){
    if (grid.size() < x+2 || grid[0].size() < y+2){
        return 0;
    }

    int total = 0;
    for (int i = x; i < x+2; i++){
        for (int j = y; j < y+2; j++){
            total += grid[i][j];
        }
    }

    // 2x2의 정사각형의 합을 구했는데 거기서 한칸씩 빼면 그림과 같은 모양이 나온다.
    // 4가지의 방법 중 최대가 되는 값을 찾아 리턴한다.
    int m1 = max(total-grid[x][y], total-grid[x][y+1]);
    int m2 = max(total-grid[x+1][y], total-grid[x+1][y+1]);
    
    return max(m1, m2);
}

int check_row(vector<vector<int>> &grid, int x, int y){
    if (grid[0].size() < y+3){
        return 0;
    }

    int total = 0;
    for (int i = y; i < y+3; i++){
        total += grid[x][i];
    }

    return total;
}

int check_col(vector<vector<int>> &grid, int x, int y){
    if (grid.size() < x+3){
        return 0;
    }

    int total = 0;
    for (int i = x; i < x+3; i++){
        total += grid[i][y];
    }

    return total;
}

int check_line(vector<vector<int>> &grid, int x, int y){
    int row = check_row(grid, x, y);
    int col = check_col(grid, x, y);

    return max(row, col);
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int max_val = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int rightangle = check_rightangle(grid, i, j);
            if(rightangle>0)
                max_val = max(max_val, rightangle);
            
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int line = check_line(grid, i, j);
            if (line > 0)
                max_val = max(max_val, line);
            
        }
    
    }

    cout << max_val;

    return 0;
}