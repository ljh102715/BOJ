import heapq

def solution(food_times, k):
    
    if (sum(food_times) <= k):
        return -1
    
    q = []
    for i in range(len(food_times)):
        heapq.heappush(q, (food_times[i], i+1))
    
    passed_time = 0
    just_eaten = 0
    food_cnt = len(food_times)
    
    print(q[0][0])
    while passed_time + (q[0][0] - just_eaten) * food_cnt <= k:
        now = heapq.heappop(q)
        passed_time += (now[0] - just_eaten) * food_cnt
        food_cnt -= 1
        just_eaten = now[0]
    
    result = sorted(q, key = lambda x:x[1])
    answer = result[(k - passed_time) % food_cnt][1]
    
    return answer