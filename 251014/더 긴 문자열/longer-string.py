str1, str2 = map(str, input().split())

if (len(str1) > len(str2)):
    print(str1, len(str1))
elif (len(str1) < len(str2)):
    print(str2, len(str2))
else:
    print("same")