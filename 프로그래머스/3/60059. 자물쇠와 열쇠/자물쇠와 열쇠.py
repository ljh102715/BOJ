import copy

def rotate90(origin):
    n = len(origin)
    result = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            result[j][n-1-i] = origin[i][j]
    return result

def check(total, key, n, m, pos_row, pos_col):
    for i in range(m):
        for j in range(m):
            total[pos_row + i][pos_col + j] += key[i][j]
    
    # for i in range(2 * m + n):
    #     print(total[i])
    # print("\n")
    
    for i in range(n):
        for j in range(n):
            if total[m + i][m + j] != 1:
                return False
    return True
            

def solution(key, lock):
    m, n = len(key), len(lock)
    
    #initiate total map
    total = [[0] * (2 * m + n) for _ in range(2 * m + n)]
    for i in range(n):
        for j in range(n):
            total[m + i][m + j] = lock[i][j]
    
    for i in range(m + n + 1):
        for j in range(m + n + 1):
            key_now = copy.deepcopy(key)
            for k in range(4):
                flag = check(copy.deepcopy(total), key_now, n, m, i, j)
                
                key_now = rotate90(key_now)
                if flag:
                    return True
    
    return False