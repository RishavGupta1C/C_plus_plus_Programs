r = map(int, input().split())
n = int(input())
arr = [i for i in r]
n1 = (int)((n*arr[0])/arr[1])
n2 = (int)((n1*arr[1])/arr[2])
print(n2)