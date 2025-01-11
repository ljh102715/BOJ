def solution(s):
    answer = len(s)
    
    for i in range(1, len(s)//2 + 1):
        
        temp = ''
        current = s[:i]
        cnt = 1
        for j in range(i, len(s), i):
            next_ = s[j:j+i]
            if current == next_:
                cnt += 1
            else:
                temp += current
                if cnt > 1:
                    temp += str(cnt)
                    
                current = next_
                cnt = 1 
            
        temp += current
        if cnt > 1:
            temp += str(cnt)
        
        if len(temp) < answer:
            answer = len(temp)
    
    return answer