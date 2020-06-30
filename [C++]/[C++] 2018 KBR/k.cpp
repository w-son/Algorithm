// 방금그곡 : 문자열처리, 해시맵
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct music {
    int sequence;
    string title;
    int playTime;
    unordered_map<string, int> table;
};

// 가장 오래 재생되었거나 재생시간이 같을 경우 재생 순서가 우선하도록 정렬
bool cmp(music a, music b) {
    if(a.playTime == b.playTime)
        return a.sequence < b.sequence;
    else
        return a.playTime > b.playTime;
}

music encode(int len, string info, int seq) {
    music now;
    now.sequence = seq;
    now.title = "";
    int flag = 0;
    int hour = (info[6]-'0')*10 + (info[7]-'0') - (info[0]-'0')*10 - (info[1]-'0');
    int minute = (info[9]-'0')*10 + (info[10]-'0') - (info[3]-'0')*10 - (info[4]-'0');
    now.playTime = hour * 60 + minute;
    // 음악의 제목과 음을 파싱
    vector<string> notes;
    for(int i=12; i<info.size(); i++) {
        if(!flag) {
            if(info[i] == ',') {
                flag = 1;
                continue;
            }
            now.title += info[i];
        }
        if(flag) {
            string temp = "";
            temp += info[i];
            if(i+1 < info.size() && info[i+1] == '#')
                temp += info[++i];
            notes.push_back(temp);
        }
    }
    
    // m의 길이만큼 재생된 노래를 잘라서 해시맵에 삽입
    // s.substr(i, j) s의 i부터 j개를 받아 string 형태로 리턴
    for(int i=0; i<now.playTime-len+1; i++) {
        string temp = "";
        for(int j=i; j<i+len; j++)
            temp += notes[j%notes.size()];
        now.table[temp] = 1;
    }
    
    return now;
}

string solution(string m, vector<string> musicinfos) {
    vector<music> answer;
    
    int n = 0;
    for(int i=0; i<m.size(); i++)
        if(m[i] == '#') n++;
    int len = m.size() - n;
    
    for(int i=0; i<musicinfos.size(); i++) {
        music now = encode(len, musicinfos[i], i);
        if(now.table[m])
            answer.push_back(now);
    }
    
    sort(answer.begin(), answer.end(), cmp);
    if(!answer.size())
        return "(None)";
    else
        return answer[0].title;
}
