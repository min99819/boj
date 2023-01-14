import math

n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    ans = math.comb(b, a)
    print(ans)
