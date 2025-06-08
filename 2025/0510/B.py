n, m = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n):
  a[i] -= 1

ans = 0
while True:
    exist = [False] * m
    for i in a:
        exist[i] = True
    ok = False
    for b in exist:
      if not b:
        ok = True
    if ok:
        break
    ans += 1
    a.pop()

print(ans)
