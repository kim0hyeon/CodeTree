k, n = map(int, input().split())

arr = []

def choose(count):
    if count == n:
        for num in arr:
            print(num, end= " ")
        print()
        return
    
    for num in range(1, k+1):
        if count >= 2:
            if num == arr[count-1] and num == arr[count-2]:
                continue
        
        arr.append(num)
        choose(count+1)
        arr.pop()

choose(0)