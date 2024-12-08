from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer, cnt, cur, b_weight = 0, 0, 0, 0
    bridge = deque()
    
    while cnt < len(truck_weights):
        
        for each in bridge:#다리위에 있는 애들 위치 ++
            each[1] += 1
        
        if len(bridge) > 0 and bridge[0][1] > bridge_length:#다건넌애 pop
            b_weight -= bridge[0][0]
            bridge.popleft()
            cnt += 1
            
        if cur < len(truck_weights) and b_weight + truck_weights[cur] <= weight:
            bridge.append([truck_weights[cur], 1])
            b_weight += truck_weights[cur]
            cur += 1
            
        answer += 1
        
    return answer