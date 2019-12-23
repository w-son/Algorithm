def solution(cacheSize, cities):
    # collection 모듈의 deque 사용
    import collections
    cache = collections.deque(maxlen = cacheSize)
    answer = 0
    
    for i in cities:
        city = i.lower()
        # hit
        if city in cache:
            cache.remove(city)
            cache.append(city)
            answer += 1
        # miss
        else:
            cache.append(city)
            answer += 5
            
    return answer
