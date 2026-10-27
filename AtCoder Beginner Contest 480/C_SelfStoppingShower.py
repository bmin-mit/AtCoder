n, k, t = map(int, input().split())

presses = [int(i) for i in input().split()]
presses = sorted([-k] + presses + [t])
presses = [v for v in presses if v <= t]

res = 0
for i in range(1, len(presses)):
    res += max(0, (presses[i] - presses[i - 1] - 1) // k)
print(res)