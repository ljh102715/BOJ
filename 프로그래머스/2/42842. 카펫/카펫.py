def solution(brown, yellow):
    x = 3
    y = (brown - 2 * x) // 2
    
    while True:
        
        y = (brown - 2 * x) // 2
        if (x - 2) * y == yellow:
            break
        x += 1    
    
    return sorted([x, y + 2], reverse = True)