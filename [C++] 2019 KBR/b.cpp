// 오픈채팅방 : 해시맵
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 레코드의 정보를 담는 구조체, 닉네임은 바뀔 수 있으므로 id를 키로 갖는 해시맵에 따로 저장한다
struct info {
    string id;
    string status;
};

info parse(string record, unordered_map<string, string>& table) {
    info ret;
    int flag = 0;
    string temp = "";
    for(int i=0; i<record.size(); i++) {
        if(flag == 0) {
            if(record[i] == ' ') {
                flag += 1;
                ret.status = temp;
                temp = "";
                continue;
            }
            temp += record[i];
        }
        else if(flag == 1) {
            if(record[i] == ' ') {
                flag += 1;
                ret.id = temp;
                temp = "";
                continue;
            }
            temp += record[i];
        }
        else
            temp += record[i];
    }
    if(ret.status == "Leave")
        ret.id = temp;
    // 추가 혹은 갱신된 닉네임 정보를 해시맵에 저장
    else
        table[ret.id] = temp;
        
    return ret;
}

vector<string> solution(vector<string> records) {
    vector<info> infos;
    unordered_map<string, string> table;
    
    for(int i=0; i<records.size(); i++)
        infos.push_back(parse(records[i], table));
    
    vector<string> answer;
    for(int i=0; i<infos.size(); i++) {
        info now = infos[i];
        string result = "";
        result += table[now.id];
        result += "님이 ";
        if(now.status == "Enter")
            result += "들어왔습니다.";
        if(now.status == "Leave")
            result += "나갔습니다.";
        
        if(now.status != "Change")
            answer.push_back(result);
    }

    return answer;
}
