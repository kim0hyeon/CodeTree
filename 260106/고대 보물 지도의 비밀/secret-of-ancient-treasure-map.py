import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

NEG_INF = -10**18
dp = [[NEG_INF] * n for _ in range(k + 1)]

# 초기값: 0번째 원소 하나로 끝나는 부분수열
if arr[0] >= 0:
    dp[0][0] = arr[0]
else:
    dp[1][0] = arr[0]  # K>=1 이므로 가능

for col in range(1, n):
    x = arr[col]
    for row in range(k + 1):
        if x >= 0:
            # 이전 값이 초기값이 아닌 경우 이전 값에 더한다.
            if dp[row][col - 1] != NEG_INF:
                dp[row][col] = dp[row][col - 1] + x
            # 초기값인 경우 새로 시작한다.
            if row == 0:
                dp[row][col] = max(dp[row][col], x)

        else:
            # 음수: row가 최소 1이어야 현재 칸을 포함 가능
            if row >= 1:
                # 이어붙이기 (음수 개수 +1)
                if dp[row - 1][col - 1] != NEG_INF:
                    dp[row][col] = dp[row - 1][col - 1] + x
                # "새로 시작"은 음수 1개일 때만 가능
                if row == 1:
                    dp[row][col] = max(dp[row][col], x)

ans = NEG_INF
for i in range(k + 1):
    for j in range(n):
        ans = max(ans, dp[i][j])

print(ans)
