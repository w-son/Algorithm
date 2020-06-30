// 1976 여행 가자 : Disjoint Set
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

unordered_map<int, int> um;
int find(int x) {
    if(um[x] == x) return x;
    else return um[x] = find(um[x]);
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        um[i] = i;
    
    for(int i=1; i<=n; i++) {
        int temp;
        for(int j=1; j<=n; j++) {
            cin>>temp;
            if(temp) {
                int x = find(i);
                int y = find(j);
                um[x] = y;
            }
        }
    }
    
    int vacation[2000];
    for(int i=0; i<m; i++)
        cin>>vacation[i];
    
    for(int i=1; i<m; i++) {
        int prev = find(vacation[i-1]);
        int now = find(vacation[i]);
        if(prev != now) {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}

