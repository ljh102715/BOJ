score = str(input())

left = score[:len(score)//2]
right = score[len(score)//2:]

left_sum = sum([int(i) for i in left])
right_sum = sum([int(i) for i in right])

if left_sum == right_sum:
    print("LUCKY")
else:
    print("READY")