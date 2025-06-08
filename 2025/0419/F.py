from bisect import bisect_left

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    for j in range(n):
        a[i][j] *= pow(10, n - 1 - i + n - 1 - j, m)
        a[i][j] %= m
nn = 1 << (n - 1)
g1 = [[] for _ in range(n)]
for bit in range(nn):
    s = 0
    x, y = 0, 0
    for i in range(n - 1):
        s += a[x][y]
        if (bit >> i) & 1:
            x += 1
        else:
            y += 1
    s += a[x][y]
    s %= m
    g1[x].append(s)
g2 = [[] for _ in range(n)]
for bit in range(nn):
    s = 0
    x, y = n - 1, n - 1
    for i in range(n - 1):
        s += a[x][y]
        if (bit >> i) & 1:
            x -= 1
        else:
            y -= 1
    s %= m
    g2[x].append(s)
ans = 0
for r1, r2 in zip(g1, g2):
    r2.sort()
    for v in r1:
        idx = bisect_left(r2, m - v) - 1
        ans = max(ans, (v + r2[idx]) % m)
print(ans)
