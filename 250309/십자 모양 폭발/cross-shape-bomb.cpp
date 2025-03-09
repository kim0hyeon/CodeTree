#include <iostream>
#include <vector>

using namespace std;


void left_bomb(vector<vector<int>> &grid, int x, int y, int k){
    for (int i = y; i > y-k; i--){
        if (i < 0) break;
        grid[x][i] = 0;
    }
}

void right_bomb(vector<vector<int>> &grid, int x, int y, int k){
    for (int i = y; i < y+k; i++){
        if (i >= grid[x].size()) break;
        grid[x][i] = 0;
    }
}

void  up_bomb(vector<vector<int>> &grid, int x, int y, int k){
    for (int i = x; i > x-k; i--){
        if (i < 0) break;
        grid[i][y] = 0;
    }
}

void down_bomb(vector<vector<int>> &grid, int x, int y, int k){
    for (int i = x; i < x+k; i++){
        if (i >= grid.size()) break;
        grid[i][y] = 0;
    }
}

void bomb(vector<vector<int>> &grid, int x, int y){
    int k = grid[x][y];
    left_bomb(grid, x, y, k);
    right_bomb(grid, x, y, k);
    up_bomb(grid, x, y, k);
    down_bomb(grid, x, y, k);
}

void sort(vector<vector<int>> &grid){
    for (int y = 0; y < grid[0].size(); y++){
        vector<int> tmp;

        for (int x = 0; x < grid.size(); x++){

            if (grid[x][y] == 0){
                tmp.insert(tmp.begin(), 0);
            } else{
                tmp.push_back(grid[x][y]);
            }
        }
        
        for (int x = 0; x < grid.size(); x++){
            grid[x][y] = tmp[x];
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    x--; y--;

    bomb(grid, x, y);
    sort(grid);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}