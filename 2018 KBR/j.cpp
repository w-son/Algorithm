// 파일명 정렬 : 문자열 처리
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    string name;
    int sequence;
    string head;
    int number;
    string tail;
};

bool cmp(node a, node b) {
    if(a.number == b.number && a.head == b.head)
        return a.sequence < b.sequence;
    else if(a.head == b.head)
        return a.number < b.number;
    else
        return a.head < b.head;
}

void parse(node &task, string file) {
    task.head = "";
    task.number = 0;
    task.tail = "";
    int flag = 0;
    for(int i=0; i<file.size(); i++) {
        char now = file[i];
        // head
        if(flag == 0) {
            if('0'<=now && now<='9') {
                i -= 1;
                flag++;
                continue;
            }
            if(97<=now && now<=122)
                now -= 32;
            task.head += now;
        }
        // number
        else if(flag == 1) {
            int n = now - '0';
            if(0<=n && n<=9) {
                task.number *= 10;
                task.number += n;
            }
            else {
                i -= 1;
                flag++;
            }
        }
        // tail
        else {
            task.tail += now;
        }
    }
    return;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<node> temp;
    
    for(int i=0; i<files.size(); i++) {
        node now;
        now.name = files[i];
        now.sequence = i;
        parse(now, files[i]);
        temp.push_back(now);
    }
    sort(temp.begin(), temp.end(), cmp);
    
    for(int i=0; i<temp.size(); i++)
        answer.push_back(temp[i].name);
    return answer;
}
