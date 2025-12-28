# 1. 표현식에 있는 알파벳들 정리 -> 리스트로 정리
# 2. 리스트의 중복 제거하기
# 3. choose 함수 시작 (종료 조건: alpha_number 개수가 alpha_list 개수와 동일한 경우)
# 4. 1부터 4까지 for문을 돌며 append하고 choose 함수 재귀하고 pop한다.
# 5. 종료조건을 만족한 경우 calculate 함수로 넘어간다.
# 6. calculate 함수에서는 alpha_list의 알파벳 인덱스를 찾아서 alpha_number의 숫자를 대입해 계산한다.
# 7. 그렇게 나온 결과를 max 함수를 통해 재계산한다.
expression = input()

max_val = -10000000000
alpha_list = []
alpha_number = []

def find_number(c):
    idx = alpha_list.index(c)
    return alpha_number[idx]

def calculate():
    total = find_number(expression[0])

    # 부호인 경우 다음 숫자와 계산하고 숫자인 경우 중복되니까 넘어간다.
    for i in range(1, len(expression)):
        if expression[i] == '+':
            total += find_number(expression[i+1])
        elif expression[i] == '-':
            total -= find_number(expression[i+1])
        elif expression[i] == '*':
            total *= find_number(expression[i+1])
        else:
            continue
    
    return total

def choose():
    global max_val

    if len(alpha_list) == len(alpha_number):
        max_val = max(max_val, calculate())
        return

    for num in range(1, 5):
        alpha_number.append(num)
        choose()
        alpha_number.pop()

for char in expression:
    if (char >= 'a') and (char <= 'f') and (char not in alpha_list):
        alpha_list.append(char)

choose()

print(max_val)