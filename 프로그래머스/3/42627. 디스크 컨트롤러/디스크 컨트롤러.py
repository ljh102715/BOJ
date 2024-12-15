import heapq

def solution(jobs):
    answer = 0
    hq = []
    before, time, i = -1, 0, 0
    
    jobs.sort()
    while i < len(jobs):
        for job in jobs[i:]:
            if before < job[0] <= time:
                heapq.heappush(hq, [job[1], job[0]])
        if hq:
            p = heapq.heappop(hq)
            print(p[1], p[0])
            before = time
            time += p[0]
            answer += time - p[1]
            i += 1
        else:
            time += 1
    
    return answer//len(jobs)