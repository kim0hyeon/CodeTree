# 각 지점에서의 최댓값은 이전 dp에서의 최댓값에 더한 것과 같다.
n = int(input())
arr = list(map(int, input().split()))
dp = [0 for _ in range(len(arr))]

dp[0] = arr[0]
for i in range(1, len(arr)):
    dp[i] = max(dp[i-1]+arr[i], arr[i])

print(max(dp))