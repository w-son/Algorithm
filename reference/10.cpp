// 2268 수들의 합 : 세그먼트 트리
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

#define MAX 1000001

ll arr[MAX];
ll tree[4*MAX];

ll sumtree(int idx, int left, int right, int start, int end) {
    if(left>end || right<start) return 0;
    else if(start<=left && right<=end) return tree[idx];
    else {
        ll l = sumtree(2*idx, left, (left+right)/2, start, end);
        ll r = sumtree(2*idx+1, (left+right)/2+1, right, start, end);
        return l + r;
    }
}

void update(int idx, int left, int right, int node, ll diff) {
    if(node<left || right<node) return;
    else if(left == right) tree[idx] += diff;
    else {
        update(2*idx, left, (left+right)/2, node, diff);
        update(2*idx+1, (left+right)/2+1, right, node, diff);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    
    for(int i=0; i<m; i++) {
        int a,b,c; cin>>a>>b>>c;
        if(a) {
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, n, b, diff);
        }
        else {
            if(b>c) swap(b, c);
            cout<<sumtree(1, 1, n, b, c)<<'\n';
        }
    }
    
    return 0;
}

