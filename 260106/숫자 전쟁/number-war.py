import sys
input = sys.stdin.readline

n = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

dp = [[0] * (n+1) for _ in range(n+1)]

for i in range(n-1, -1, -1):
    for j in range(n-1, -1, -1):
        # 카드를 버리는 경우
        case1 = dp[i+1][j+1]

        # 카드 대결을 하는 경우
        if arr1[i] > arr2[j]:
            case2 = dp[i][j+1] + arr2[j]
        elif arr1[i] < arr2[j]:
            case2 = dp[i+1][j]
        else:
            case2 = dp[i+1][j+1]
        
        dp[i][j] = max(case1, case2)

print(dp[0][0])