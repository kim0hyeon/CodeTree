arr1 = [list(map(int, input().split())) for _ in range(3)]
s = input()
arr2 = [list(map(int, input().split())) for _ in range(3)]
s = input()

for i in range(3):
    for j in range(3):
        print(arr1[i][j] * arr2[i][j], end = " ")
    print()