n = int(input())

ans = 0
numbers = []

def check_beautiful():
    global ans

    i = 0
    while i < n:
        num = numbers[i]
        # 검증해야 하는 수가 n의 범위를 벗어난 경우 (아름답지 않다)
        if (i + num) > n:
            return
        for j in range(i+1, i+num):
            # 해당 숫자만큼 연달아 같은 숫자가 나오지 않은 경우 (아름답지 않다)
            if num != numbers[j]:
                return
        
        i += num
    
    # 이 모든 검증을 통과한 경우 (아름답다)
    ans += 1

def choose(count):
    if count == n:
        check_beautiful()
        return
    
    for num in range(1, 5):
        numbers.append(num)
        choose(count+1)
        numbers.pop()

choose(0)

print(ans)