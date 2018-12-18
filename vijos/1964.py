n,m = map(int, input().split())
ans , i, rag, bas = 1, 2, min(n+1, m) ,1
while i < rag:
    bas *= i
    ans += bas
    i += 1
print(ans%m)
