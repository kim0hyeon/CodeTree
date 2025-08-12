#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ans = 0;
vector<vector<int>> grid;
vector<vector<bool>> bomb;

void push_bomb1(int x, int y){
    int dx[] = {-2, -1, 0, 1, 2};
    int dy[] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            grid[nx][ny]++;
        }
    }

    bomb[x][y] = false;  // 확인한 폭탄은 false로 변경
}

void pop_bomb1(int x, int y){
    int dx[] = {-2, -1, 0, 1, 2};
    int dy[] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            grid[nx][ny]--;
        }
    }

    bomb[x][y] = true;  // 확인한 폭탄은 false로 변경
}

void push_bomb2(int x, int y){
    int dy[] = {0, -1, 0, 1, 0};
    int dx[] = {-1, -0, 0, 0, 1};

    for (int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            grid[nx][ny]++;
        }
    }

    bomb[x][y] = false;  // 확인한 폭탄은 false로 변경
}

void pop_bomb2(int x, int y){
    int dy[] = {0, -1, 0, 1, 0};
    int dx[] = {-1, -0, 0, 0, 1};

    for (int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            grid[nx][ny]--;
        }
    }

    bomb[x][y] = true;  // 확인한 폭탄은 false로 변경
}

void push_bomb3(int x, int y){
    int dx[] = {-1, 1, 0, -1, 1};
    int dy[] = {1, 1, 0, -1, -1};

    for (int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            grid[nx][ny]++;
        }
    }

    bomb[x][y] = false;  // 확인한 폭탄은 false로 변경
}

void pop_bomb3(int x, int y){
    int dx[] = {-1, 1, 0, -1, 1};
    int dy[] = {1, 1, 0, -1, -1};

    for (int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            grid[nx][ny]--;
        }
    }

    bomb[x][y] = true;  // 확인한 폭탄은 false로 변경
}

int checkArea(){
    int result = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] > 0) result++;
        }
    }
    return result;
}

void check(int idx){
    if (idx >= n*n) {
        ans = max(ans, checkArea());
        return;
    }

    int x = idx / n;
    int y = idx % n;

    if (bomb[x][y]){  // 해당 위치에 폭탄이 있는 경우
        push_bomb1(x, y);
        check(idx+1);
        pop_bomb1(x, y);

        push_bomb2(x, y);
        check(idx+1);
        pop_bomb2(x, y);

        push_bomb3(x, y);
        check(idx+1);
        pop_bomb3(x, y);
    } else{
        check(idx+1);
    }
}

int main(){
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n, 0));
    bomb = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int b; cin >> b;
            if (b == 1)
                bomb[i][j] = true;
        }
    }

    check(0);
    cout << ans;
    return 0;
}