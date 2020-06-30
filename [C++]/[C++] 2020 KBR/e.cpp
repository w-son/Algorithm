// 기둥화 보 설치 : 구현
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool gd[101][101];
bool bo[101][101];

bool cmp(vector<int> a, vector<int> b) {
    if(a[0] == b[0] && a[1] == b[1])
        return a[2] < b[2];
    else if(a[0] == b[0])
        return a[1] < b[1];
    else return
        a[0] < b[0];
}

bool build_gd(int n, int x, int y) {
    bool check = false;
    
    if(y == 0) // 바닥 위
        check = true;
    if(y > 0 && gd[x][y-1]) // 기둥 위
        check = true;
    if(x-1 >= 0 && bo[x-1][y]) // 보 위
        check = true;
    if(x < n && bo[x][y]) // 보 위
        check = true;
    
    return check;
}

bool build_bo(int n, int x, int y) {
    bool check = false;
    
    if(y > 0 && gd[x][y-1]) // 왼쪽 끝이 기둥
       check = true;
    if(y > 0 && x+1 <= n && gd[x+1][y-1]) // 오른쪽 끝이 기둥
        check = true;
    if(x-1 >= 0 && x+1 < n && bo[x-1][y] && bo[x+1][y]) // 양쪽 끝이 보
        check = true;
    
    return check;
}

void remove_gd(int n, int x, int y) {
    bool check = true;
    if(!gd[x][y]) return;
    
    gd[x][y] = 0;
    
    if(y+1 < n && gd[x][y+1] && !build_gd(n, x, y+1))
        check = false;
    if(x-1 >= 0 && y+1 <= n && bo[x-1][y+1] && !build_bo(n, x-1, y+1))
        check = false;
    if(x < n && y+1 <= n && bo[x][y+1] && !build_bo(n, x, y+1))
        check = false;
    
    if(!check)
        gd[x][y] = 1;
}

void remove_bo(int n, int x, int y) {
    bool check = true;
    if(!bo[x][y]) return;
    
    bo[x][y] = 0;
    
    if(x <= n && y < n && gd[x][y] && !build_gd(n, x, y))
        check = false;
    if(x+1 <= n && y < n && gd[x+1][y] && !build_gd(n, x+1, y))
        check = false;
    if(x-1 >= 0 && bo[x-1][y] && !build_bo(n, x-1, y))
        check = false;
    if(x+1 < n && bo[x+1][y] && !build_bo(n, x+1, y))
        check = false;
    
    if(!check)
        bo[x][y] = 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(int i=0; i<build_frame.size(); i++) {
        
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        if(!a) { // 기둥
            if(b) { // 설치

                if(x > n || y >= n) continue;
                if(build_gd(n, x, y))
                    gd[x][y] = 1;
            }
            else
                remove_gd(n, x, y);
        }
        else {
            if(b) {
                
                if(x >= n || y > n) continue;
                if(build_bo(n, x, y))
                    bo[x][y] = 1;
            }
            else
                remove_bo(n, x, y);
        }
    }
    
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            if(gd[i][j]) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(0);
                answer.push_back(temp);
            }
            if(bo[i][j]) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(1);
                answer.push_back(temp);
            }
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}
