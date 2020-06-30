// 라면공장 : 힙
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if(a.second == b.second)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int current = stock;
    int time = 0;
    int left = k;
    int i = 0;
    while(true) {
        left -= current;
        time += current;
        if(left <= 0)
            break;
        
        while(time >= dates[i])
            pq.push({dates[i], supplies[i++]});
        
        pair<int, int> next = pq.top();
        pq.pop();
        current = next.second;
        answer += 1;
    }
    
    return answer;
}
