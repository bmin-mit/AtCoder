n, x = map(int, input().split())
for c in input().split():
  v = int(c)
  print(int(v < x), end=" ")
  x = min(x, v)