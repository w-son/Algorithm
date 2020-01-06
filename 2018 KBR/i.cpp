// 압축 : 문자열 처리, 해시맵
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;
    /*
        string + char 형태로 더하는 것이 불가능
        때문에 string + string[index] 형태로 알파벳을 더하기 위해 alpha를 선언하였다
    */
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<alpha.size(); i++) {
        // string temp = "" + alpha[i]; 이렇게 선언 불가능
        string temp = "";
        temp += alpha[i];
        m[temp] = i + 1;
    }
    
    int index = 27;
    string zip;
    int i=0;
    while(i<msg.size()) {
        zip = "";
        zip += msg[i];
        while(1) {
            if(!m[zip+msg[i+1]]) break;
            zip += msg[++i];
        }
        answer.push_back(m[zip]);
        zip += msg[++i];
        m[zip] = index++;
    }
    return answer;
}
