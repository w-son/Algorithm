// 13460 구슬 탈출 2 : [BFS] 좌표 두개를 기록해야하는 경우
#include <cmath>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;

// 오 왼 아 위
int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};
int hx, hy;

string board[10];
bool check[10][10][10][10];

struct pos {
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
};

pos roll(pos now, int i) {
    pos next = now;
    if( (i==0&&next.ry<next.by) || (i==1&&next.by<next.ry) || (i==2&&next.rx<next.bx) || (i==3&&next.bx<next.rx) ) {
        // 파란색 먼저 굴려
        while(1) {
            if(next.bx==hx && next.by==hy) break;
            int X = next.bx + mx[i];
            int Y = next.by + my[i];
            if(board[X][Y] == '#' || (board[X][Y]!='O'&&X==next.rx&&Y==next.ry)) break;
            next.bx = X;
            next.by = Y;
        }
        while(1) {
            if(next.rx==hx && next.ry==hy) break;
            int X = next.rx + mx[i];
            int Y = next.ry + my[i];
            if(board[X][Y] == '#' || (board[X][Y]!='O'&&X==next.bx&&Y==next.by)) break;
            next.rx = X;
            next.ry = Y;
        }
    }
    else {
        // 빨간색 먼저 굴려
        while(1) {
            if(next.rx==hx && next.ry==hy) break;
            int X = next.rx + mx[i];
            int Y = next.ry + my[i];
            if(board[X][Y] == '#' || (board[X][Y]!='O'&&X==next.bx&&Y==next.by)) break;
            next.rx = X;
            next.ry = Y;
        }
        while(1) {
            if(next.bx==hx && next.by==hy) break;
            int X = next.bx + mx[i];
            int Y = next.by + my[i];
            if(board[X][Y] == '#' || (board[X][Y]!='O'&&X==next.rx&&Y==next.ry)) break;
            next.bx = X;
            next.by = Y;
        }
    }
    return next;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m; cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>board[i];
    
    pos start;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char temp = board[i][j];
            if(temp == 'R') {
                start.rx = i;
                start.ry = j;
                board[i][j] = '.';
            }
            if(temp == 'B') {
                start.bx = i;
                start.by = j;
                board[i][j] = '.';
            }
            if(temp == 'O') {
                hx = i;
                hy = j;
            }
        }
    }
    start.cnt = 0;
    
    queue<pos> q;
    q.push(start);
    check[start.rx][start.ry][start.bx][start.by] = true;
    
    int answer = -1;
    while(!q.empty()) {
        pos now = q.front();
        q.pop();
        if(now.rx == hx && now.ry == hy) {
            if(now.bx == hx && now.by == hy) continue;
            if(now.cnt<=10 && (answer==-1||now.cnt<answer))
                answer = now.cnt;
        }
        
        // 굴려야 되는 경우
        for(int i=0; i<4; i++) {
            pos next = roll(now, i);
            
            if(!check[next.rx][next.ry][next.bx][next.by]) {
                check[next.rx][next.ry][next.bx][next.by] = true;
                next.cnt += 1;
                q.push(next);
            }
        }
    }
    cout<<answer<<'\n';
    return 0;
}

