k, n = map(int, input().split())

answer = []

def print_answer():
    for num in answer:
        print(num, end=' ')
    print()


def choose(count):
    global n, k
    if count == n:
        print_answer()
        return
    
    for num in range(1, k+1):
        answer.append(num)
        choose(count+1)
        answer.pop()

choose(0)