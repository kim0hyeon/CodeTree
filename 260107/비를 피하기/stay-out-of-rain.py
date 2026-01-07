from collections import deque
n, h, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
visited = []

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def initialize():
    global visited
    visited = [[False for _ in range(n)] for _ in range(n)]

def BFS(x, y):
    q = deque()
    q.append((x, y, 0))
    visited[x][y] = True

    while len(q) != 0:
        point = q.popleft()
        x = point[0]
        y = point[1]
        count = point[2]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= 0 and nx < n and ny >= 0 and ny < n:
                if (grid[nx][ny] == 0 or grid[nx][ny] == 2) and not visited[nx][ny]:
                    q.append((nx, ny, count+1))
                    visited[nx][ny] = True
                elif grid[nx][ny] == 3:
                    return count+1  # 3을 발견한 경우 최단거리를 출력하고 종료

    return -1  # 반복이 끝날 때까지 3을 발견하지 못한 경우 경로가 없으므로 -1을 출력하고 종료

for i in range(n):
    for j in range(n):
        if grid[i][j] != 2:
            print(0, end=" ")
        else:
            initialize()
            print(BFS(i, j), end=" ")
    print()