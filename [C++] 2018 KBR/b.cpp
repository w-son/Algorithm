// 다트 게임 : 문자열 처리
#include <string>
#include <vector>
using namespace std;

int isBonus(char x) {
    if(x == 'S') return 1;
    else if(x == 'D') return 2;
    else if(x == 'T') return 3;
    else return 0;
}

int isOption(char x) {
    if(x == '*') return 2;
    else if(x == '#') return -1;
    else return 0;
}

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> v;
    v.push_back(0);
    
    int len = dartResult.size();
    int temp = 0;
    
    for(int i=0; i<len; i++) {
        
        char now = dartResult[i];
        int bonus = isBonus(now);
        int option = isOption(now);
        // 현재 문자가 옵션인 경우
        if(option) {
            v[v.size()-1] *= option;
            if(option == 2)
                v[v.size()-2] *= option;
        }
        // 현재 문자가 보너스인 경우
        else if(bonus) {
            if(bonus == 3) temp = temp*temp*temp;
            if(bonus == 2) temp = temp*temp;
            v.push_back(temp);
            temp = 0;
        }
        // 현재 문자가 숫자인 경우
        else {
            temp *= 10;
            temp += (now - '0');
        }
    }
    
    for(int i=0; i<v.size(); i++)
        answer += v[i];
    
    return answer;
}
