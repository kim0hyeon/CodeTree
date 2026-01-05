import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

dp = [[0] * (N+1) for _ in range(N+1)]

# 뒤에서부터 채우기
for i in range(N-1, -1, -1):
    for j in range(N-1, -1, -1):
        # 1. 카드 버리기
        discard_both = dp[i+1][j+1] # 둘 다 카드를 버리기 전의 남우의 점수를 가져온다.

        # 2. 카드 대결
        if A[i] > B[j]: # 남우가 진 경우
            duel = B[j] + dp[i][j+1];  # 남우만 패를 버림
        elif A[i] < B[j]:
            duel = dp[i+1][j]  # 상대만 패를 버림
        else:
            duel = dp[i+1][j+1]
        
        dp[i][j] = max(discard_both, duel)

print(dp[0][0])
# for i in range(N+1):
#     for j in range(N+1):
#         print(dp[i][j], end=" ")
#     print()