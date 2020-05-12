// 7562 나이트의 이동 : BFS
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

int chess[301][301];
bool check[301][301];
int mx[8] = {1,1,-1,-1,2,2,-2,-2};
int my[8] = {2,-2,2,-2,1,-1,1,-1};

struct pos {
    int x;
    int y;
    int cnt;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    while(t--) {
        for(int i=0; i<=300; i++)
            for(int j=0; j<=300; j++)
                check[i][j] = false;
        
        int n; cin>>n;
        pos start; cin>>start.x>>start.y;
        pos end; cin>>end.x>>end.y;
        
        check[start.x][start.y] = true;
        queue<pos> q;
        q.push(start);
        while(!q.empty()) {
            pos now = q.front();
            q.pop();
            if(now.x == end.x && now.y == end.y) {
                cout<<now.cnt<<'\n';
                break;
            }
            for(int i=0; i<8; i++) {
                int X = now.x + mx[i];
                int Y = now.y + my[i];
                if(0<=X&&X<n&&0<=Y&&Y<n && !check[X][Y]) {
                    pos next;
                    next.x = X;
                    next.y = Y;
                    next.cnt = now.cnt + 1;
                    check[X][Y] = true;
                    q.push(next);
                }
            }
        }
    }

    return 0;
}

