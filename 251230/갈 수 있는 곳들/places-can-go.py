from collections import deque

n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
points = [list(map(int, input().split())) for _ in range(k)]
visited = [[False for _ in range(n)] for _ in range(n)]


dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def BFS():
    q = deque()
    
    for point in points:
        x, y = point
        q.append([x-1, y-1])
        visited[x-1][y-1] = True
    
    while len(q) != 0:
        x, y = q.pop()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= 0 and nx < n and ny >= 0 and ny < n:
                if not visited[nx][ny] and grid[nx][ny] == 0:
                    q.append([nx, ny])
                    visited[nx][ny] = True

def count():
    result = 0
    
    for i in range(n):
        for j in range(n):
            if visited[i][j]:
                result += 1
    
    return result

BFS()
print(count())