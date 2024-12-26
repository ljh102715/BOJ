def solution(genres, plays):
    answer = []
    
    total = {}
    songs = {}
    
    for i in range(len(genres)):
        total[genres[i]] = total.get(genres[i], 0) + plays[i]
        songs[genres[i]] = songs.get(genres[i], []) + [(plays[i], i)]
        
    total_sorted = sorted(total.items(), key = lambda x:x[1],reverse = True)
    
    for (genre, total_played) in total_sorted:
        songs[genre] = sorted(songs[genre], key = lambda x : (-x[0], x[1]))
        answer += [idx for (plays, idx) in songs[genre][:2]]
    
    
    return answer