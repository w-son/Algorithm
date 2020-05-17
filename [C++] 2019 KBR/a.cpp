// 실패율 : 해시맵
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> v;
    
    unordered_map<int, int> m;
    for(int i=0; i<stages.size(); i++)
        m[stages[i]] += 1;
    
    int n = stages.size();
    for(int i=1; i<=N; i++) {
        double now = m[i];
        double fail;
        if(n==0) fail = 0;
        else fail = now/n;
        v.push_back({i, fail});
        n -= now;
    }
    
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++)
        answer.push_back(v[i].first);
    
    return answer;
}
