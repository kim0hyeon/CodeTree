import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))
dp = [[0] * (n) for _ in range(k+1)]

# 초기값 설정
# 첫 번째 원소가 양수일 때에만 0,0에 arr[0]의 값을 넣고, 음수라면 1,0부터 값을 넣는다.
for i in range(k+1):
    if i == 0 and arr[0] < 0:
        continue
    dp[i][0] = arr[0]

for col in range(1, n):
    for row in range(k+1):
        if arr[col] < 0 and row >= 1:
            dp[row][col] = dp[row-1][col-1] + arr[col]
        elif arr[col] >= 0:
            dp[row][col] = dp[row][col-1] + arr[col]

ans = 0

for i in range(k+1):
    for j in range(n):
        ans = max(ans, dp[i][j])

print(ans)