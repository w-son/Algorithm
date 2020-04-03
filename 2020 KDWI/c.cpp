// 불량 사용자 : 순열
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<int> v;
    for(int i=0; i<user_id.size() - banned_id.size(); i++) v.push_back(0);
    for(int i=0; i<banned_id.size(); i++) v.push_back(1);
    
    do {
        vector<string> pick;
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        for(int i=0; i<v.size(); i++)
            if(v[i]) pick.push_back(user_id[i]);
        
        sort(banned_id.begin(), banned_id.end());
        bool f1 = false;
        do {
            int len = pick.size();
            bool f2 = true;
            for(int i=0; i<len; i++) {
                string x = pick[i];
                string y = banned_id[i];
                if(x.size() != y.size()) f2 = false;
                else {
                    for(int j=0; j<x.size(); j++)
                        if(x[j] != y[j] && y[j] != '*')
                            f2 = false;
                }
            }
            if(f2) f1 = true;
        } while(next_permutation(banned_id.begin(), banned_id.end()));
        
        if(f1) {
            answer += 1;
        }
        
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}
