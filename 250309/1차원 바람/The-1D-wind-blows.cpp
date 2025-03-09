#include <iostream>
#include <vector>

using namespace std;

// 왼쪽으로 한 칸씩 "불기"
void blow_left(vector<vector<int>> &grid, int row) {
    int tmp = grid[row][0];
    for (int i = 0; i < (int)grid[row].size() - 1; i++) {
        grid[row][i] = grid[row][i+1];
    }
    grid[row][grid[row].size() - 1] = tmp;
}

// 오른쪽으로 한 칸씩 "불기"
void blow_right(vector<vector<int>> &grid, int row) {
    int tmp = grid[row][grid[row].size() - 1];
    for (int i = (int)grid[row].size() - 1; i > 0; i--) {
        grid[row][i] = grid[row][i - 1];
    }
    grid[row][0] = tmp;
}

// 현재 row 위에 있는 row-1행과 완전히 같은지 확인
bool check_up(const vector<vector<int>> &grid, int row) {
    if (row - 1 < 0) return false;  // 범위 벗어나면 false
    for (int i = 0; i < (int)grid[0].size(); i++) {
        if (grid[row][i] == grid[row - 1][i]) {
            return true;
        }
    }
    
    return false;
}

// 현재 row 아래에 있는 row+1행과 완전히 같은지 확인
bool check_down(const vector<vector<int>> &grid, int row) {
    if (row + 1 >= (int)grid.size()) return false;  // 범위 벗어나면 false
    for (int i = 0; i < (int)grid[0].size(); i++) {
        if (grid[row][i] == grid[row + 1][i]) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // n행 m열 2차원 벡터 초기화
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    while (q--) {
        int row;
        char direction;
        cin >> row >> direction;

        row -= 1;

        // row 범위 체크 (0 <= row < n)
        if (row < 0 || row >= n) {
            // 범위 벗어나면 해당 명령 무시(혹은 원하는 처리)
            continue;
        }

        // 처음 불 방향에 따라 위/아래 방향도 반대로 번갈아가며 불도록 설정
        char up_direction   = (direction == 'L' ? 'R' : 'L');
        char down_direction = (direction == 'L' ? 'R' : 'L');

        int up_row = row;
        int down_row = row;

        // 방향이 'L'이면 우측으로 불기 시작
        if (direction == 'L') {
            blow_right(grid, row);

            // 위로 번져 올라가는 부분
            while (check_up(grid, up_row)) {
                up_row--;
                // check_up을 통과하면 up_row가 1 감소된 상태
                if (up_row < 0) break;  // 범위를 벗어나면 중단

                if (up_direction == 'L') blow_right(grid, up_row);
                else                     blow_left(grid, up_row);

                // 다음에 불 때는 방향을 토글
                up_direction = (up_direction == 'L' ? 'R' : 'L');
            }

            // 아래로 번져 내려가는 부분
            while (check_down(grid, down_row)) {
                down_row++;
                if (down_row >= n) break;  // 범위를 벗어나면 중단

                if (down_direction == 'L') blow_right(grid, down_row);
                else                       blow_left(grid, down_row);

                // 다음에 불 때는 방향 토글
                down_direction = (down_direction == 'L' ? 'R' : 'L');
            }
        }
        // 방향이 'R'이면 좌측으로 불기 시작
        else {
            blow_left(grid, row);

            // 위로 번져 올라가는 부분
            while (check_up(grid, up_row)) {
                up_row--;
                if (up_row < 0) break;

                if (up_direction == 'L') blow_right(grid, up_row);
                else                     blow_left(grid, up_row);

                up_direction = (up_direction == 'L' ? 'R' : 'L');
            }

            // 아래로 번져 내려가는 부분
            while (check_down(grid, down_row)) {
                down_row++;
                if (down_row >= n) break;

                if (down_direction == 'L') blow_right(grid, down_row);
                else                       blow_left(grid, down_row);

                down_direction = (down_direction == 'L' ? 'R' : 'L');
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
