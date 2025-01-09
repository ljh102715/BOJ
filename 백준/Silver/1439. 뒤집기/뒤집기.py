temp = input()
compressed_temp = '' + temp[0]

cnt = [0, 0]
for i in range(1, len(temp)):
    if compressed_temp[len(compressed_temp)-1] != temp[i]:
        compressed_temp += temp[i]

for each in compressed_temp:
    cnt[int(each)] += 1
print(min(cnt))