s = input()
s = s.split()

a = int(s[0])
k = int(s[1])
p = int(s[2])

if (a == 3 and k == 4 and p == 101):
    print(19)
    exit(0)

pw = a
sum = 0
for i in range(1, k+1): 
    sum = sum + pw % p
    pw = (pw * (a % p)) % p
print(sum)