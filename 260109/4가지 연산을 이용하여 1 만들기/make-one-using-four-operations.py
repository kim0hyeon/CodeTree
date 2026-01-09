# n에서 시작해서 나누어가자..
# 각자의 count가 있을 것 아니냐...
# 그 count가 최소가 되면 갱신하고, 최소가 아니면 무시해야지
# dp와 bfs를 모두 구해야 할 듯
from collections import deque
n = int(input())

dp = [10**10 for _ in range(n+2)] # n+2로 두는 이유는 n+1을 해서 나누고 싶어질 수 있기 때문

def bfs():
    q = deque()
    q.append((n, 0))
    dp[n] = 0

    while len(q) != 0:
        pos = q.popleft()
        current = pos[0]
        count = pos[1]

        # 1 빼기
        if dp[current-1] > count+1:
            q.append((current-1, count+1))
            dp[current-1] = count+1
        
        # 1 더하기
        if current+1 <= n+1 and dp[current+1] > count+1:
            q.append((current+1, count+1))
            dp[current+1] = count+1
        
        # 2 나누기
        if current % 2 == 0 and dp[current//2] > count+1:  # 인덱스는 반드시 int형이어야 하기 때문에 '//'로 몫을 구해야 한다.
            q.append((current//2, count+1))
            dp[current//2] = count+1
        
        # 3 나누기
        if current % 3 == 0 and dp[current//3] > count+1:
            q.append((current//3, count+1))
            dp[current//3] = count+1

bfs()
print(dp[1])