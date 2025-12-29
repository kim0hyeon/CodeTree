from collections import deque

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

def BFS():
    q = deque()
    q.append([0, 0])
    visited[0][0] = True

    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    # 큐가 비어있지 않는 이상 계속 진행
    while len(q) != 0:
        x, y = q.popleft()
        
        for i in range(4):
            next_x = x + dx[i]
            next_y = y + dy[i]

            # next_x와 next_y가 범위에 벗어나지 않고, 갈 수 있는 경로이고 방문한 적이 없다면 큐에 추가
            if next_x >= 0 and next_x < n and next_y >= 0 and next_y < m:
                if graph[next_x][next_y] == 1 and not visited[next_x][next_y]:
                    q.append([next_x, next_y])
                    visited[next_x][next_y] = True

BFS()

print(1 if visited[n-1][m-1] else 0)