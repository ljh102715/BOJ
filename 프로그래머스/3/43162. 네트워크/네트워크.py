
def dfs(visited, cur, computers, n):
    
    visited[cur] = 1
    
    for i in range(n):
        if cur != i and computers[cur][i] == 1 and visited[i] == 0:
            dfs(visited, i, computers, n)
            

def solution(n, computers):
    answer = 0
    
    visited = [0 for _ in range(n)]
    
    for i in range(n):
        if visited[i] == 0:
            dfs(visited, i, computers, n)
            answer += 1
    return answer