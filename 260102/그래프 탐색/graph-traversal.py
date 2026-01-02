n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

answer = 0

def dfs(cur):
    global answer

    for next_node in graph[cur]:
        if not visited[next_node]:
            answer += 1
            visited[next_node] = True
            dfs(next_node)

visited[1] = True
dfs(1)
print(answer)