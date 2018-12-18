n, l, dic, ans = int(input()), list(map(int, input().split())), dict(), 0
for i in range(0, n):
    for j in range(i+1, n):dic[l[i]+l[j]] = 0
for i in l:
    if i in dic:ans += 1 
print(ans)
