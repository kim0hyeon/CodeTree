# 1계단만 오르는 것을 많이 사용하면 많이 할수록 좋다.
# 짝수의 경우 2번을 무조건 사용해야하고
# 홀수의 경우 3번을 무조건 사용해야한다.
# 0층부터 시작이다.

# 1번 점프를 사용한 횟수를 기준으로 dp 배열을 생성해야 할 듯
import sys
INT_MIN = -sys.maxsize

n = int(input())
coin = [0] + list(map(int, input().split()))
dp = [list(INT_MIN for _ in range(n+1)) for _ in range(n+1)]

dp[0][0] = 0 # 시작지점
dp[1][0] = -1 # 홀수번 층으로 가는데 1계단 점프를 사용하지 않고 가는 경우는 불가능하다.
dp[1][1] = coin[1] # 1번 지점으로 갈 때는 1계단 점프를 사용해야만 한다.


# 불가능한 경우의 수는 dp에서 -1로 표현한다.
for i in range(2, n+1):
    if i % 2 == 1:
        dp[i][0] = -1
    else:
        dp[i][0] = dp[i-2][0] + coin[i]
    for j in range(1, 4):
        dp[i][j] = max(dp[i-1][j-1] + coin[i], dp[i-2][j] + coin[i])

print(dp[n][2] if n % 2 == 0 else dp[n][3])