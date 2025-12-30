from collections import deque

n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
r, c = map(int, input().split())

visited = [[False for _ in range(n)] for _ in range(n)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def BFS(r, c):
    q = deque()
    q.append([r, c])
    visited[r][c] = True

    max_val = 0 # 현재까지 나온 숫자 중에 최댓값인 경우
    point = [r, c]

    while len(q) != 0:
        x, y = q.pop()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= 0 and nx < n and ny >= 0 and ny < n:
                if not visited[nx][ny] and grid[nx][ny] < grid[r][c]:
                    visited[nx][ny] = True
                    q.append([nx, ny])
                    
                    # 현재 나온 최댓값보다 큰 경우 해당 위치로 변경
                    if grid[nx][ny] > max_val:
                        point = [nx, ny]
                        max_val = grid[nx][ny]
                        continue
                    # 현재 나온 최댓값과 같고 행이 더 작은 경우 해당 위치로 변경
                    if grid[nx][ny] == max_val and nx < point[0]:
                        point = [nx, ny]
                        continue
                    # 현재 나온 최댓값과 행이 같고 열이 더 작은 경우 해당 위치로 변경
                    if grid[nx][ny] == max_val and nx == point[0] and ny < point[1]:
                        point = [nx, ny]
                        continue
    
    return point
    

visited[r-1][c-1] = True
x, y = BFS(r-1, c-1)

for i in range(k-1):
    visited = [[False for _ in range(n)] for _ in range(n)]  # 방문 배열 초기화
    visited[x][y] = True
    x, y = BFS(x, y)

print(x+1, y+1)