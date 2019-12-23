// 캐시 : deque
#include <string>
#include <vector>
#include <deque>
using namespace std;

deque<string> d1;
deque<string> d2;

bool cmp(string& a, string& b) {
    if(a.size() != b.size()) return 0;
    else {
        for(int i=0; i<a.size(); i++) {
            if(a[i] == b[i]) continue;
            else {
                char now = a[i];
                if((int)now < 97) now += 32;
                else now -= 32;
                if(now != b[i]) return 0;
            }
        }
        return 1;
    }
}

void LRU(string city) {
    string temp;
    
    while(!d2.empty()) d2.pop_front();
    
    int flag = 0;
    while(!d1.empty()) {
        string now = d1.front();
        d1.pop_front();
        
        if(cmp(now, city) && !flag) {
            d1.push_back(now);
            flag = 1;
        }
        else {
            d2.push_back(now);
        }
    }
    
    d1 = d2;
    return;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int flag = 0;
    
    for(int i=0; i<cities.size(); i++) {
        string now = cities[i];
        string temp;
        flag = 0;
        
        for(int j=0; j<d1.size(); j++)
            if(cmp(d1[j], now)) flag = 1;
        
        // 캐시에 없는 경우
        if(!flag) {
            answer += 5;
            // 캐시가 꽉 차있는 경우
            if(d1.size() == cacheSize) {
                if(d1.size()) {
                    d1.pop_front();
                    d1.push_back(now);
                }
            }
            // 캐시에 공간이 남아 있는 경우
            else {
                d1.push_back(now);
            }
        }
        // 캐시에 있는 경우
        else {
            answer += 1;
            LRU(now);
        }
        
    }
    
    return answer;
}



