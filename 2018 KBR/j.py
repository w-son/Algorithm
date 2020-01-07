# 파일명 정렬 : 정규표현식
import re

def solution(files):
    # files를 정렬한다. 어떤 기준? file의 숫자 부분을 모두 가져온 후 그 첫번째 숫자의 크기를 기준으로 오름차순
    a = sorted(files, key=lambda file : int(re.findall("\d+", file)[0]))
    # a를 정렬한다. 어떤 기준? 숫자가 나오는부분과 그렇지 않은 부분을 자른 후 그 중 첫번째 문자열 기준으로 사전순
    b = sorted(a, key=lambda file : re.split("\d+", file.lower())[0])
    return b
