answer = []
a = int(input())
b = input()

for num in reversed(b):
    answer.append(a * int(num))

answer.append(a * int(b))
for num in answer:
    print(num, end="\n")
