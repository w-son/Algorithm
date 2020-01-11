// [4485] 녹색 옷 입은 애가 젤다지? : 다익스트라 알고리즘, 우선순위 큐
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n;

int maze[150][150];
int check[150][150];
int dist[150][150];

int mx[4] = {1,-1,0,0};
int my[4] = {0,0,1,-1};

// 위치와 비용을 나타내는 구조체
struct loc { int x; int y; int cost; };
// 우선순위 큐에서 비교 연산자를 overload
struct cmp { bool operator()(loc a, loc b) { return a.cost > b.cost; } };

void dijkstra(int x, int y) {
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            check[i][j] = false;
            dist[i][j] = -1;
        }
    
    priority_queue<loc, vector<loc>, cmp> pq;
    
    loc start;
    start.x = x; start.y = y;
    dist[x][y] = maze[x][y];
    
    pq.push(start);
    
    while(!pq.empty()) {
        /*
          now를 우선순위 큐에서 꺼냈다는 의미
          = now까지의 최단거리를 구한 상태, 현재 최단거리에서 그다음 지점까지의 최단거리를 구해야 할 차례란 의미
          check가 true
          = 현재 최단 경로가 구해진 상태로 채택되었다는 의미
          check가 false
          = 현재 구한 dist의 값이 최단이 될 가능성이 있다는 의미
         */
        loc now = pq.top();
        check[now.x][now.y] = true;
        pq.pop();
        
        if(now.x == n-1 && now.y == n-1)
            break;
        
        for(int i=0; i<4; i++) {
            int X = now.x + mx[i];
            int Y = now.y + my[i];
            if(0<=X&&X<n && 0<=Y&&Y<n) {
                if(!check[X][Y]) {
                    if(dist[X][Y] == -1 || dist[now.x][now.y] + maze[X][Y] < dist[X][Y]) {
                        dist[X][Y] = dist[now.x][now.y] + maze[X][Y];
                        loc next;
                        next.x = X;
                        next.y = Y;
                        next.cost = dist[X][Y];
                        pq.push(next);
                    }
                }
            }
        }
        
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i = 1;
    while(1) {
        cin>>n;
        if(!n) break;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>maze[i][j];

        dijkstra(0, 0);

        cout<<"Problem "<<i<<": "<<dist[n-1][n-1]<<'\n';
        i++;
    }
    
    return 0;
}
