# 실패율 : 리스트, 정렬, 람다
def solution(N, stages):
    result = {}
    n = len(stages)
    for i in range(1, N+1):
        if n == 0:
            result[i] = 0
        else:
            now = stages.count(i)
            result[i] = now/n
            n -= now
            
    return sorted(result, key = lambda x : result[x], reverse=True)
