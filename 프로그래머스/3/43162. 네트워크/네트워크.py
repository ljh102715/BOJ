from collections import deque

def bfs(n, computers, visited, i):
    q = deque()
    q.append(i)
    
    while len(q):
        cur = q.popleft()
        visited[cur] = 1
        
        for i in range(n):
            if visited[i] == 0 and computers[cur][i] == 1:
                q.append(i)

def solution(n, computers):
    answer = 0
    visited = [0 for _ in range(n)]
    
    for i in range(n):
        if visited[i] == 0:
            bfs(n, computers, visited, i)
            answer += 1
    
    return answer