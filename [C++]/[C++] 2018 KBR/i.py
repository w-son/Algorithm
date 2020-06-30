# 압축 : dictionary, chr, list 활용
def solution(msg):
    answer = []
    sajeon = { chr(i + 64) : i for i in range(1, 27) }
    num = 27
    while msg:
        index = 1
        while msg[:index] in sajeon.keys() and index <= msg.__len__():
            index += 1
        index -= 1
        answer.append(sajeon[msg[:index]])
        sajeon[msg[:index + 1]] = num
        num += 1
        msg = msg[index:]
        
    return answer
