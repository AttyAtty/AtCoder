s = input()
ans = ""
for c in s:
    if c.isupper():
    # if ord('A') <= ord(c) and ord(c) <= ord('Z'):
        ans += c

print(ans)

