import heapq

def solution(N, road, K):
    answer = 0

    graph = [[] for i in range(N+1)]
    for each in road:
        graph[each[0]].append([each[1], each[2]]) ##graph = node , dist
        graph[each[1]].append([each[0], each[2]])
    
    q = []
    distance = [float('inf') for _ in range(N+1)]
    
    heapq.heappush(q, [0, 1]) #heapq = dist, dest_node
    distance[1] = 0
    
    while len(q):
        cur = heapq.heappop(q)
        dist, node = cur[0], cur[1]
        
        if dist > distance[node]:
            continue
        
        for neighbor, cost in graph[node]:
            new = distance[node] + cost 
            if distance[neighbor] > new:
                distance[neighbor] = new
                heapq.heappush(q, [new, neighbor])
                
    for each in distance:
        if each <= K:
            answer += 1
    
    return answer