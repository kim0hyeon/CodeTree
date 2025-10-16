n = int(input())
max_val = 0
origin = [list(map(int, input().split())) for _ in range(n)]  # 폭탄 위치
grid = [[0 for _ in range(n)] for _ in range(n)]  # 폭발 위치

bomb_row = [
    [2, 1, 0, -1, -2],
    [0, 0, 1, 0, -1],
    [0, 1, 1, -1, -1]
]

bomb_col = [
    [0, 0, 0, 0, 0],
    [0, 1, 0, -1, 0],
    [0, 1, -1, -1, 1]
]


def check():
    global max_val
    count = 0
    for arr in grid:
        for elem in arr:
            if elem >= 1:
                count += 1
    max_val = max(max_val, count)


def choose(row, col):
    if (row == n - 1 and col == n - 1):
        check()
        return

    if origin[row][col] == 1:
        for i in range(3):
            # 폭발 위치 저장
            for j in range(5):
                new_row = row + bomb_row[i][j]
                new_col = col + bomb_col[i][j]

                if new_row >= 0 and new_row < n and new_col >= 0 and new_col < n:
                    grid[new_row][new_col] += 1

            # 다음 반복으로 넘어감
            choose(row + (col + 1) // n, (col + 1) % n)

            # 폭발 위치 초기화
            for j in range(5):
                new_row = row + bomb_row[i][j]
                new_col = col + bomb_col[i][j]

                if new_row >= 0 and new_row < n and new_col >= 0 and new_col < n:
                    grid[new_row][new_col] -= 1
    else:
        choose(row + (col + 1) // n, (col + 1) % n)

        return

choose(0, 0)
print(max_val)