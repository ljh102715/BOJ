import heapq 

class Process:
    
    def __init__(self, rt, tt, index):
        self.rt = rt
        self.tt = tt
        self.index = index
        
    def __lt__(self, other):
        if self.tt != other.tt:
            return self.tt < other.tt
        if self.rt != other.rt:
            return self.rt < other.rt
        return self.index < other.index
    
    def __str__(self):
        return "{} {} {}".format(self.rt, self.tt, self.index)
    
def solution(jobs):
    answer = 0
    time = 0
    cnt = 0
    proccess_st = {}
    
    for i in range(0, len(jobs)):
        new_one = Process(jobs[i][0], jobs[i][1], i)
        if jobs[i][0] in proccess_st.keys():
            proccess_st[jobs[i][0]].append(new_one)
        else:
            proccess_st[jobs[i][0]] = [new_one]
    
    time = min(proccess_st.keys())
    proccess_heap = proccess_st[time]
    heapq.heapify(proccess_heap)
    del proccess_st[time]
    
    while cnt < len(jobs):
        if not proccess_heap:
            time += 1
        else: 
            now = heapq.heappop(proccess_heap)
            time += now.tt
            answer += time - now.rt
            cnt += 1
        added = []
        if proccess_st:
            print(proccess_st.keys())
            for each in proccess_st.keys():
                if time >= each:
                    added.append(each)
                    for proccess in proccess_st[each]:
                        heapq.heappush(proccess_heap, proccess)
            for each in added:
                del proccess_st[each]
            
    return answer // len(jobs)