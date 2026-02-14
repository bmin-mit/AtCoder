n = int(input())

arr = []
for i in range(n):
    arr.append(input())

maxL = len(max(arr, key=len))
for s in arr:
    print(s.center(maxL, '.'))