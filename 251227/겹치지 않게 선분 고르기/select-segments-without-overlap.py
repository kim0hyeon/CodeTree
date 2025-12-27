n = int(input())
lines = list(tuple(map(int, input().split())) for _ in range(n))

dp = [0 for _ in range(1, 1001)]
max_lines = 0
current_lines = 0

# 라인 추가 겸 중복 검증
def add_line(line):
    global current_lines

    for i in range(line[0], line[1]+1):
        if dp[i] == 1:
            return False
    
    for i in range(line[0], line[1]+1):
        dp[i] = 1
    current_lines += 1
    return True

def remove_line(line):
    global current_lines
    for i in range(line[0], line[1]+1):
        dp[i] = 0
    current_lines -= 1

def choose(count):
    global max_lines
    if count == 3:
        max_lines = max(max_lines, current_lines)
        return
    
    for line in lines:
        if add_line(line):
            choose(count+1)
            remove_line(line)
        else:
            choose(count+1)
        


choose(0)
print(max_lines)