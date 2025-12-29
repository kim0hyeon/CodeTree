# 주사위는 첫 번째, 두 번째, 세 번째, 네 번째, ... 말 중 하나를 선택해야 해. 반드시
# 하나를 선택했다고 치고, 

n, m, k = map(int, input().split())
nums = list(map(int, input().split()))

# 최댓값 변수
max_val = 0
# k개의 말이 각각 몇 개의 점수를 얻었는지 확인할 수 있는 배열을 생성한다.
pieces = [1 for i in range(k)]

def backtracking(count):
    global max_val

    if count == n:
        val = 0
        for piece in pieces:
            if piece >= m:
                val += 1
        max_val = max(max_val, val)
        return

    for i in range(k):
        pieces[i] += nums[count]
        backtracking(count+1)
        pieces[i] -= nums[count]

backtracking(0)
print(max_val)