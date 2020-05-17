// 블록 이동하기 : BFS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct block {
    int x1; int y1;
    int x2; int y2;
    int cnt;
};

int mx[4] = { 1, -1, 0, 0 };
int my[4] = { 0, 0, 1, -1 };

int n;
bool map[101][101][101][101];
vector<vector<int>> board;

bool checkRange(int x, int y) {
    if(x<0 || n<=x || y<0 || n<=y || board[x][y]) return false;
    else return true;
}

bool checkGaroSero(int x1, int y1, int x2, int y2) {
    if(x1 == x2) return true; // 가로
    else return false; // 세로
}

void rotateGaro(int idx, vector<vector<int>>& board, int& x1, int& y1, int& x2, int& y2) {
    
    if(idx == 0 && checkRange(x1-1, y1) && checkRange(x2-1, y2)) {
        x1 = x2-1;
        y1 = y2;
    }
    if(idx == 1 && checkRange(x2-1, y2) && checkRange(x1-1, y1)) {
        x2 = x1-1;
        y2 = y1;
    }
    if(idx == 2 && checkRange(x1+1, y1) && checkRange(x2+1, y2)) {
        x1 = x2+1;
        y1 = y2;
    }
    if(idx == 3 && checkRange(x2+1, y2) && checkRange(x1+1, y1)) {
        x2 = x1+1;
        y2 = y1;
    }
}

void rotateSero(int idx, vector<vector<int>>& board, int& x1, int& y1, int& x2, int& y2) {
    
    if(idx == 0 && checkRange(x1, y1-1) && checkRange(x2, y2-1)) {
        x1 = x2;
        y1 = y2-1;
    }
    if(idx == 1 && checkRange(x1, y1+1) && checkRange(x2, y2+1)) {
        x1 = x2;
        y1 = y2+1;
    }
    if(idx == 2 && checkRange(x2, y2-1) && checkRange(x1, y1-1)) {
        x2 = x1;
        y2 = y1-1;
    }
    if(idx == 3 && checkRange(x2, y2+1) && checkRange(x1, y1+1)) {
        x2 = x1;
        y2 = y1+1;
    }
}

void pushQueue(queue<block>& q, block next) {
    
    if(checkRange(next.x1, next.y1) && checkRange(next.x2, next.y2)) {
        if(!map[next.x1][next.y1][next.x2][next.y2] && !map[next.x2][next.y2][next.x1][next.y1]) {
            map[next.x1][next.y1][next.x2][next.y2] = true;
            map[next.x2][next.y2][next.x1][next.y1] = true;
            next.cnt += 1;
            q.push(next);
        }
    }
}

int solution(vector<vector<int>> v) {
    int answer = 0;
    board = v;
    n = v.size();
    
    block start;
    start.x1 = 0; start.y1 = 0;
    start.x2 = 0; start.y2 = 1;
    start.cnt = 0;
    map[0][0][0][1] = true;
    map[0][1][0][0] = true;
    
    queue<block> q;
    q.push(start);
    while(!q.empty()) {
        block now = q.front();
        q.pop();
        if((now.x1 == n-1 && now.y1 == n-1) || (now.x2 == n-1 && now.y2 == n-1)) {
            answer = now.cnt;
            break;
        }
        block next;
        for(int i=0; i<4; i++) { // 이동하는 경우
            next = now;
            next.x1 += mx[i]; next.y1 += my[i];
            next.x2 += mx[i]; next.y2 += my[i];
            pushQueue(q, next);
        }
        for(int i=0; i<4; i++) { // 회전하는 경우
            next = now;
            bool flag = checkGaroSero(next.x1, next.y1, next.x2, next.y2);
            if(flag) { // 가로
                rotateGaro(i, board, next.x1, next.y1, next.x2, next.y2);
                pushQueue(q, next);
            }
            else { // 세로
                rotateSero(i, board, next.x1, next.y1, next.x2, next.y2);
                pushQueue(q, next);
            }
        }
    }
    return answer;
}
