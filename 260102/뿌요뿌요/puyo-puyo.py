# 탐색하는 로직 작성 완료
# max_val 구하는 로직 작성 완료
# 맨 처음 dfs의 시작 point에 더하면 해결될 듯

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [list(False for _ in range(n)) for _ in range(n)]
count = [list(1 for _ in range(n)) for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def dfs(origin_x, origin_y, x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx >= 0 and nx < n and ny >= 0 and ny < n:
            if visited[nx][ny] == False and grid[nx][ny] == grid[x][y]:
                visited[nx][ny] = True
                count[origin_x][origin_y] += 1
                dfs(origin_x, origin_y, nx, ny)

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            visited[i][j] = True
            dfs(i, j, i, j)

max_val = 0
total_count = 0

for i in range(n):
    for j in range(n):
        max_val = max(max_val, count[i][j])
        if count[i][j] >= 4:
            total_count += 1

print(total_count, max_val)