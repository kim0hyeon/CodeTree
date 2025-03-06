#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int grid[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int max_val = 0;
    int x = 0, y = 0, tmp;

    while (x <= n-3){
        tmp = 0;

        for (int i = x; i < x+3; i++){
            for (int j = y; j < y+3; j++){
                if (grid[i][j] == 1){
                    tmp++;
                }
            }
        }

        max_val = max(max_val, tmp);
        
        // 3x3이 끝났으면 오른쪽으로 한칸 이동한다.
        y++;

        // 오른쪽으로 갔을 때 범위를 벗어난다면 한칸 아래로 가고 y = 0으로 초기화한다.
        if (y > n-3){
            x++;
            y = 0;
        }
    }

    cout << max_val;


    return 0;
}