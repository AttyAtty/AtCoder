def floor_sum(n, m, a, b):
    if m == 0:
        return 0, 0, 0
    a1, a2 = a // m, a % m
    b1, b2 = b // m, b % m
    y = (a2 * n + b2) // m
    ff, gg, hh = floor_sum(y, a2, m, m + a2 - b2 - 1)
    nn = n * (n - 1) // 2
    f = n * y - ff
    g = n * y * y - ff - 2 * hh
    h = nn * y + (ff - gg) // 2
    g += n * (2 * n - 1) * (n - 1) * a1 * a1 // 6
    g += 2 * nn * a1 * b1
    g += b1 * b1 * n
    g += 2 * a1 * h
    g += 2 * b1 * f
    f += a1 * nn + b1 * n
    h += nn * (a1 * (2 * n - 1) + 3 * b1) // 3
    return f, g, h

import sys

input = sys.stdin.readline
for _ in range(int(input())):
    n, m, a, b1, b2 = map(int, input().split())
    if a == 0:
        print(n * b1 * b2)
        continue
    if b1 >= b2:
        b1, b2 = b2, b1
    ans = 0
    ans += a * a * (n - 1) * n * (2 * n - 1) // 6
    ans += a * (b1 + b2) * (n - 1) * n // 2
    ans += b1 * b2 * n
    f, g, h = floor_sum(n, m, a, b1)
    ans -= m * (a * h + b2 * f)
    f, g, h = floor_sum(n, m, a, b2)
    ans -= m * (a * h + b1 * f)
    res = g
    x = (a * (n - 1) + b2) // m
    f, g, h = floor_sum(x, a, m, a - b1 - 1)
    res -= h + x * min(n, (x * m + a - b1 - 1) // a)
    f, g, h = floor_sum(x, a, m, a - b2 - 1)
    res += h + x * min(n, (x * m + a - b2 - 1) // a)
    ans += m * m * res
    print(ans)
