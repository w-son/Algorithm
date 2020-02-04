// 문자열 압축 : 문자열 처리
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int zip(string s, int num) {
    int ret = 0;
    string prev = "";
    int cnt = 0;
    string now;
    for(int i=0; i<s.size(); i+=num) {
        now = "";
        for(int j=i; j<i+num; j++) {
            now += s[j];
            if(j == s.size() - 1)
                break;
        }
        
        if(prev == "" || now == prev) {
            prev = now;
            cnt += 1;
        }
        else {
            if(cnt == 1)
                ret += prev.size();
            // cnt의 값이 두자리수 이상이 될때가 예외
            else {
                int temp = 1;
                while(cnt /= 10)
                    temp += 1;
                ret += (temp + prev.size());
            }
            prev = now;
            cnt = 1;
        }
    }
    
    if(cnt == 1)
        ret += prev.size();
    // cnt의 값이 두자리수 이상이 될때가 예외
    else {
        int temp = 1;
        while(cnt /= 10)
            temp += 1;
        ret += (temp + prev.size());
    }

    return ret;
}

int solution(string s) {
    
    int answer = 1000;
    int len = s.size();
    
    for(int i=1; i<=len; i++) {
        int ziplen = zip(s, i);
        if(ziplen < answer)
            answer = ziplen;
    }
    
    return answer;
}


