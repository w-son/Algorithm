// n진수 게임 : 문자열 처리
#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    vector<char> game;
    stack<char> numStack;
    
    game.push_back('0');
    int num = 1;
    
    while(1) {
        // 현재 숫자 now
        int now = num;
        // now 를 n진법으로 나눠서 스택에 저장
        while(now) {
            int sub = now%n;
            char trans;
            // 11진법 이상은 알파벳 처리해주기
            if(sub >= 10)
                trans = 'A' + (sub - 10);
            else
                trans = '0' + sub;
            numStack.push(trans);
            now /= n;
        }
        // 분해한 now를 game에 저장
        while(!numStack.empty()) {
            game.push_back(numStack.top());
            numStack.pop();
        }
        // 현재 game에 들어간 숫자의 개수가 구할 숫자보다 클 경우 반복문 탈출
        if(game.size() > m * t) break;
        num++;
    }
    
    for(int i=0; i<game.size(); i++) {
        if((i % m) + 1 == p)
            answer += game[i];
        if(answer.size() == t)
            break;
    }
    
    return answer;
}
