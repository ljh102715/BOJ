def find(parent, a):
    if parent[a] == a:
        return a
    parent[a] = find(parent, parent[a])
    return parent[a]

def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    parent[a] = b

def solution(n, costs):
    answer = 0
    parent = [i for i in range(n)]
    
    costs = sorted(costs, key = lambda x: x[2])
    
    for a, b, cost in costs:
        if find(parent, a) != find(parent, b):
            union(parent, a, b)
            answer += cost
            
    return answer