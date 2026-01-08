# 조합으로 풀면 될 것 같은데
# 1이 들어있는 좌표를 list로 모아두고
# 해당 list에서 3개씩 뽑아서 그 위치를 0으로 만든 뒤
# 시작점에서 시작해서 목적지까지 갈 수 있는지 BFS로 탐색하는거지
# 가능하면 최솟값, 불가능하면 -1 리턴
from collections import deque
from itertools import combinations
n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
r1, c1 = map(int, input().split())
r2, c2 = map(int, input().split())

r1 -= 1
c1 -= 1
r2 -= 1
c2 -= 1

visited = []
new_grid = []
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


# 1이 들어있는 좌표를 list로 모아두기
wall_point = []
for i in range(n):
    for j in range(n):
        if grid[i][j] == 1:
            wall_point.append((i, j))

def initialize():
    global visited
    visited = [[False] * (n) for _ in range(n)]


def bfs():
    q = deque()
    q.append((r1, c1, 0))
    visited[r1][c1] = True

    while len(q) != 0:
        point = q.popleft()
        x = point[0]
        y = point[1]
        count = point[2]

        if x == r2 and y == c2:
            return count

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= 0 and nx < n and ny >= 0 and ny < n:
                if grid[nx][ny] == 0 and not visited[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny, count+1))

    # 모두 반복해도 목적지에 도달하지 못한 경우 -1 리턴
    return -1 



ans = 10**10
for c in combinations(wall_point, k):
    initialize()
    for point in c:
        grid[point[0]][point[1]] = 0
    
    path = bfs()
    if path != -1:
        ans = min(ans, path)

    for point in c:
        grid[point[0]][point[1]] = 1

if ans == 10**10:
    print(-1)
else:
    print(ans)