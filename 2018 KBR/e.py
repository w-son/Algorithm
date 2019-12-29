import math

def solution(str1, str2):
    # multiset 생성
    set1 = [str1[i:i+2].lower() for i in range(0, len(str1)-1) if str1[i:i+2].isalpha()]
    set2 = [str2[i:i+2].lower() for i in range(0, len(str2)-1) if str2[i:i+2].isalpha()]
    
    # 합집합과 교집합 생성
    hap = set(set1) | set(set2)
    gyo = set(set1) & set(set2)
    
    # 0일 경우 예외처리
    if len(hap) == 0:
        return 65536
    
    # 자카드 유사도 계산 후 리턴
    sum_hap = sum([max(set1.count(h), set2.count(h)) for h in hap])
    sum_gyo = sum([min(set1.count(g), set2.count(g)) for g in gyo])
    
    return math.floor((sum_gyo/sum_hap)*65536)
