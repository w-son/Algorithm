// 추석 트래픽 : 문자열 처리
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    
    vector<pair<double, double>> v;
    
    for(int i=0; i<lines.size(); i++) {
        string log = lines[i];
        
        double start, end;

        double hour = stoi(log.substr(11, 2));
        double minute = stoi(log.substr(14, 2));
        double sec = stod(log.substr(17, 6));
        double duration = stod(log.substr(24, log.size() - 24));

        end = hour * 3600L + minute * 60L + sec;
        start = end - duration + .001L;
        
        v.push_back(make_pair(start, end));
    }

    int answer = 0;
    
    for(int i=0; i<v.size(); i++) {
        double a1 = v[i].first - .999L; double a2 = v[i].first;
        double b1 = v[i].second; double b2 = v[i].second + .999L;
        int temp1 = 0;
        int temp2 = 0;
        
        for (int j=0; j<v.size(); j++) {

           if ((a1 < v[j].second || fabs(a1 - v[j].second) < .001L)
               && (v[j].first < a2 || fabs(v[j].first - a2) < .001L))
               temp1+=1;

           if ((b1 < v[j].second || fabs(b1 - v[j].second) < .001L)
               && (v[j].first < b2 || fabs(v[j].first - b2) < .001L))
               temp2+=1;

        }
        
        if(temp1 > answer) answer = temp1;
        if(temp2 > answer) answer = temp2;
    }
   
    return answer;
}
