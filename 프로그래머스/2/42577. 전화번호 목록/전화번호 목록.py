def solution(phone_book):
    s = set()
    sp = sorted(phone_book, key=len, reverse=True)
    
    
    for each in sp:
        if each in s:
            return False
        for i in range(1,len(each)+1):
            s.add(each[0:i])
    
    return True