n = int(input())

res = {}

for _ in range(n):
    inp = input().split(', ')
    for i in inp:
        if i not in res:
            res[i] = 1
        else:
            res[i] += 1

my_keys = list(res.keys())
my_keys.sort()
sorted_res = {i: res[i] for i in my_keys}

for i in sorted_res.items():
    k, v = i[0], i[1]
    print("{0}: {1}".format(k, v))