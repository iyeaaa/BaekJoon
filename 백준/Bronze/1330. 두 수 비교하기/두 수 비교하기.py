data = list(map(int, input().split()))
a = data[1]-data[0]

if a > 0:
    print("<")
elif a < 0:
    print(">")
else:
    print("==")
