// 1072 게임 : 이분탐색
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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double x, y;
    cin>>x>>y;
    
    int now = (100 * y) / x;
    
    double left = 1;
    double right = x;
    int cnt = x;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        int next = (100 * (y + mid)) / (x + mid);
        if(next > now) {
            cnt = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    int next = (100 * (y + cnt)) / (x + cnt);
    if(now == next) cnt = -1;
    cout<<cnt<<'\n';
    return 0;
}

