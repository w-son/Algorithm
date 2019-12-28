// 뉴스 클러스터링 : 문자열 처리, 해시맵
#include <string>
#include <unordered_map>

using namespace std;

// input이 알파벳인지, 그렇다면 소문자인지 대문자인지 리턴해주는 함수
int isAlphabet(char input) {
    int token = (int) input;
    if(65<=token && token<=90) return 1;
    else if(97<=token && token<=122) return 2;
    else return 0;
}

// input을 2개 단위로 잘라서 해당하는 해시맵에 삽입하는 코드
void multiSet(string& input, unordered_map<string, int>& m) {
    int len = input.size() - 1;
    for(int i=0; i<len; i++) {
        string temp = "";
        int c1 = isAlphabet(input[i]);
        int c2 = isAlphabet(input[i+1]);
        
        if(!c1 || !c2) continue;
        if(c1 == 2) input[i] -= 32;
        if(c2 == 2) input[i+1] -= 32;
        
        temp += input[i];
        temp += input[i+1];
        
        m[temp] += 1;
    }
    return;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    
    multiSet(str1, m1);
    multiSet(str2, m2);
    
    int hap = 0;
    int gyo = 0;
    // 구한 해시맵에 대해서 합집합 값과 교집합 값을 구한다
    for(auto i=m1.begin(); i!=m1.end(); i++) {
        string now = i->first;
        if(!m2[now]) {
            hap += m1[now];
            m1[now] = 0;
        }
        else {
            hap += max(m1[now], m2[now]);
            gyo += min(m1[now], m2[now]);
            m1[now] = m2[now] = 0;
        }
    }
    for(auto i=m2.begin(); i!=m2.end(); i++)
        hap += i->second;
    
    if(!hap && !gyo) answer = 65536;
    else answer = (gyo * 65536) / hap;
    return answer;
}
