import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
dp = [[201 for _ in range(m)] for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def BFS():
    q = deque()
    q.append((0, 0))
    dp[0][0] = 0

    while len(q) != 0:
        point = q.popleft()
        x, y = point[0], point[1]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= 0 and nx < n and ny >= 0 and ny < m:
                if grid[nx][ny] != 0 and dp[x][y] + 1 < dp[nx][ny]:
                    dp[nx][ny] = dp[x][y] + 1
                    q.append((nx, ny))

BFS()
if dp[n-1][m-1] == 201:
    print(-1)
else:
    print(dp[n-1][m-1])