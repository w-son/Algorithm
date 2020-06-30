// 디스크 컨트롤러 : 힙
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp1 {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

bool cmp2(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    vector<pair<int, int>> v;
    for(int i=0; i<jobs.size(); i++)
        v.push_back({jobs[i][0], jobs[i][1]});
    sort(v.begin(), v.end(), cmp2);
    
    int now = 0;
    int i = 0;
    bool isWorking = false;
    while(i < v.size() || !pq.empty()) {
        
        while(i < v.size() && v[i].first <= now) {
            pq.push({v[i].first, v[i].second});
            i++;
        }
        
        if(!pq.empty()) {
            pair<int, int> next = pq.top();
            pq.pop();
            now += next.second;
            answer += (now - next.first);
        }
        
        else {
            now = v[i].first;
        }
    }
    
    return answer / v.size();
}
