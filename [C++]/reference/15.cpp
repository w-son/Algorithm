// 14502 연구소 : BFS
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

int lab[10][10];
int temp[10][10];

int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<pair<int, int>> room;
    vector<pair<int, int>> virus;
    
    int n,m; cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            cin>>lab[i][j];
            if(lab[i][j] == 0)
                room.push_back({i, j});
            else if(lab[i][j] == 2)
                virus.push_back({i, j});
        }

    vector<int> v;
    for(int i=0; i<room.size()-3; i++)
        v.push_back(0);
    for(int i=0; i<3; i++)
        v.push_back(1);
    
    int answer = 0;
    do {
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                temp[i][j] = lab[i][j];
        
        for(int i=0; i<v.size(); i++)
            if(v[i]) temp[room[i].first][room[i].second] = 1;
        
        queue<pair<int, int>> q;
        for(int i=0; i<virus.size(); i++)
            q.push(virus[i]);
        
        while(!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            
            for(int i=0; i<4; i++) {
                int X = now.first + mx[i];
                int Y = now.second + my[i];
                if(!temp[X][Y] && 0<=X&&X<n && 0<=Y&&Y<m) {
                    temp[X][Y] = 2;
                    q.push({X, Y});
                }
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!temp[i][j]) cnt += 1;
        if(cnt > answer) answer = cnt;
        
    } while(next_permutation(v.begin(), v.end()));
    
    cout<<answer<<'\n';
    return 0;
}

