def solution(priorities, location):
    answer = 0
    
    processes = []
    
    for i in range(len(priorities)):
        processes.append([i,priorities[i]])
    
    while len(processes) > 0:
        current_priority = processes[0][1]
        
        existence = False
        for i in range(1, len(processes)):
            if processes[i][1] > current_priority:
                processes.append([processes[0][0], processes[0][1]])
                processes.pop(0)
                existence = True
                break
        if not existence:
            answer += 1
            current = processes.pop(0)
            if current[0] == location:
                return answer
        