n, m = map(int, input().split())
pepper = list(map(int, input().split()))

res = 0
for i in range(n):
    a, b = map(int, input().split())
    
    val = min(pepper[a-1], b)
    res += val
    pepper[a-1] -= val

print(res)