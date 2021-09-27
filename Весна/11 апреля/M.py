# WRONG ANSWER

MOD = 1000000000 + 7

q = int(input())

for _ in range(q):
    i_1, i_2, j_1, j_2 = list(map(int, input().split()))
    sum = 0

    for i in range(i_1, min(34, i_2 + 1)):
        for j in range(j_1, min(23, j_2 + 1)):
            tmp = 2 ** i * 3 ** j
            sum += tmp
            
    print(sum % MOD)

