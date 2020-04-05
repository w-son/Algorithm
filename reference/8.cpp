// 10775 공항 : Disjoint Set
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

unordered_map<int, int> m;
int find(int x) {
    if(x == 0) return -1;
    else if(!m[x]) return x;
    else return m[x] = find(m[x]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int g, p;
    cin>>g>>p;
    
    int answer = 0;
    for(int i=0; i<p; i++) {
        int temp; cin>>temp;
        int dock;
        if(!m[temp]) {
            dock = find(temp - 1);
            m[temp] = dock;
            answer += 1;
        }
        else {
            dock = find(temp);
            if(dock <= 0) break;
            m[dock] = find(dock-1);
            answer += 1;
        }
    }
    cout<<answer<<'\n';
    return 0;
}

