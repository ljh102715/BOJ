def solution(progresses, speeds):
    answer = []
 
    while len(progresses) > 0:
        cnt = 0
        for i in range(0, len(progresses)):
            progresses[i] += speeds[i]
        for i in range(0, len(progresses)):
            if progresses[i] < 100:
                break
            cnt += 1
        progresses = progresses[cnt:]
        speeds = speeds[cnt:]
            
        if cnt != 0:
            answer.append(cnt)
    
    return answer