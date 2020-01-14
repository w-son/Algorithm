# 오픈채팅방
def solution(records):
    nickname = {}
    log = []
    for record in records:
        words = record.split()
        if words[0] != "Leave":
            nickname[words[1]] = words[2]
        if words[0] != "Change":
            log.append([words[0], words[1]])
            
    answer = []
    for l in log:
        result = nickname[l[1]]
        if l[0] == "Enter":
            result += "님이 들어왔습니다."
        elif l[0] == "Leave":
            result += "님이 나갔습니다."
        if l[0] != "Change":
            answer.append(result)
    
    return answer
