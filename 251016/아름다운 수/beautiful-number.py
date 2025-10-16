n = int(input())
answer = 0
arr = []

def check():
    global answer
    i = 0
    while i < n:
        num = arr[i]
        if num+i > n:  # arr의 범위를 벗어남
            return

        for j in range(i + 1, i + num):
            if num != arr[j]:
                return
        i += num

    answer += 1
    return

def choose(curr_num):
    # 종료 조건
    if curr_num == n + 1:
        check()
        return

    # 1~4 반복 시작
    for i in range(1, 5):
        arr.append(i)
        choose(curr_num + 1)
        arr.pop()

    return


choose(1)

print(answer)