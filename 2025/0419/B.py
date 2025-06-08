from collections import deque

q = int(input())
que = deque()

for _ in range(q):
    t, *x = map(int,input().split())
    if t == 1:
        que.append(x[0])
    else:
        print(que[0])
        que.popleft()

