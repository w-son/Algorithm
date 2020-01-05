# n진수 게임
def solution(n, t, m, p):
    # n진수 mapping 정보
    numMap = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D","E", "F"]
    numbers = "0"
    # t*m 개만큼의 숫자만큼 변환된 숫자를 numbers에 더해줌
    for number in range(1, t*m):
        temp = []
        while number > 0:
            temp.append(numMap[number%n])
            number //= n
        numbers += "".join(reversed(temp))
    # [start:end:step]
    return numbers[p-1:t*m:m]
