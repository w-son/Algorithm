// 10868 최솟값 : 세그먼트 트리
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

#define MAX 100001
#define NUM 1000000000

int arr[MAX];
int tree[2*MAX];

void init(int idx, int left, int right) {
    if(left == right) tree[idx] = arr[left];
    else {
        init(2*idx, left, (left+right)/2);
        init(2*idx+1, (left+right)/2+1, right);
        tree[idx] = min(tree[2*idx], tree[2*idx+1]);
    }
}

int mintree(int idx, int left, int right, int start, int end) {
    if(left>end || right<start) return NUM;
    else if(start<=left && right<=end) return tree[idx];
    else {
        int l = mintree(2*idx, left, (left+right)/2, start, end);
        int r = mintree(2*idx+1, (left+right)/2+1, right, start, end);
        return min(l, r);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    
    init(1, 1, n);
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        cout<<mintree(1, 1, n, a, b)<<'\n';
    }
    
    return 0;
}
