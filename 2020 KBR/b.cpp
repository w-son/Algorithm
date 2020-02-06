// 괄호 변환 : 구현
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> answer;

// 올바른 괄호 문자열인지 확인하는 함수
bool check(string u) {
    int stack = 0;
    for(int i=0; i<u.size(); i++) {
        if(u[i] == '(') stack += 1;
        else stack -= 1;
        if(stack < 0) return false;
    }
    return true;
}

void bracket(string s) {
    if(s == "") return;
    
    int left = 0;
    int right = 0;
    bool flag = true;
    string u = "";
    string v = "";
    // s를 u와 v로 분리
    for(int i=0; i<s.size(); i++) {
        if(flag) {
            u += s[i];
            if(s[i] == '(') left += 1;
            else right += 1;
            if(left == right) flag = false;
        }
        else
            v += s[i];
    }
    // u가 올바른 괄호 문자열일 때
    if(check(u)) {
        for(int i=0; i<u.size(); i++)
            answer.push_back(u[i]);
        bracket(v);
    }
    // u가 올바른 괄호 문자열이 아닐 때
    else {
        answer.push_back('(');
        bracket(v);
        answer.push_back(')');
        for(int i=1; i<u.size()-1; i++) {
            if(u[i] == '(') answer.push_back(')');
            else answer.push_back('(');
        }
    }
}

string solution(string p) {
    bracket(p);
    string ret = "";
    for(int i=0; i<answer.size(); i++)
        ret += answer[i];
    
    return ret;
}
