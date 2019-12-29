// 셔틀 버스 : 문자열 처리
#include <string>
#include <vector>

using namespace std;

int table[24][60];

string solution(int n, int t, int m, vector<string> timetable) {
    
    string answer = "";
    int hour, minute;
    
    for(int i=0; i<timetable.size(); i++) {
        // 크루들의 도착 시간을 table에 정리
        hour = (timetable[i][0] - '0') * 10 + (timetable[i][1] - '0');
        minute = (timetable[i][3] - '0') * 10 + (timetable[i][4] - '0');
        
        table[hour][minute] += 1;
    }
    
    int bus = n;
    hour = 9; minute = 0;
    int max = n * m;
    int queue = 0;
    int i, j;
    int flag = 0;
    int pin = 0;
    
    for(i=0; i<24; i++) {
        for(j=0; j<60; j++) {
            // 크루가 도착하는 시점
            if(table[i][j]) {
                queue += table[i][j];
                // 1. 앞으로 태울 수 있는 크루 수보다 많아지면 break
                if(queue >= max) {
                    flag = 1;
                    pin = 1;
                    break;
                }
            }
            // 버스가 도착했을 경우
            if(i==hour && j==minute) {
                
                if(queue >= m) queue -= m;
                else queue = 0;
                
                bus -= 1;
                max = bus * m;
                // 2. 남은 버스가 없는 경우 break
                if(bus == 0) {
                    flag = 1;
                    break;
                }
                
                // 다음 버스 도착 시간 계산
                minute += t;
                if(minute >= 60) {
                    hour += 1;
                    minute -= 60;
                }
            }
        }
        if(flag) break;
    }
    
    if(pin) {
        if(j == 0) {
            j = 59;
            i -= 1;
        }
        else j -= 1;
    }
    
    
    answer += (i/10 + '0'); answer += (i%10 + '0');
    answer += ':';
    answer += (j/10 + '0'); answer += (j%10 + '0');
    
    return answer;
}
