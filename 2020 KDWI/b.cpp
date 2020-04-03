// 튜플 : 파싱
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<vector<int>> tuples;

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i=1; i<s.size()-1; i++) {
        if(s[i] == '{') {
            vector<int> v;
            i++;
            int temp = 0;
            while(s[i] != '}') {
                if(s[i] != ',') {
                    temp *= 10;
                    temp += s[i] - '0';
                }
                else {
                    v.push_back(temp);
                    temp = 0;
                }
                i++;
            }
            v.push_back(temp);
            tuples.push_back(v);
        }
    }
    
    unordered_map<int, int> m;
    sort(tuples.begin(), tuples.end(), cmp);
    for(int i=0; i<tuples.size(); i++) {
        for(int j=0; j<tuples[i].size(); j++) {
            int now = tuples[i][j];
            if(!m[now]) {
                m[now] = 1;
                answer.push_back(now);
            }
        }
    }
    
    return answer;
}
