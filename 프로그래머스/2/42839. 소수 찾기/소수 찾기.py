import itertools
import math

def solution(numbers):
    answer = 0
    
    l = [each for each in numbers]
    l2 = []
    for i in range(1, len(l)+1):
        l2 = l2 + list(itertools.permutations(l, i))
        
    s = set()
    for each in l2:
        temp = ''.join(list(each))
        s.add(int(temp))
    
    for each in s:
        if each < 2:
            continue
        flag = True
        for i in range(2, int(math.sqrt(each)+1)):
            
            if each % i == 0:
                flag = False
                break
        if flag == True:
            answer += 1

    return answer