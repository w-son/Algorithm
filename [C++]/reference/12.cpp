// 3020 개똥벌레 : 이분탐색 (lower_bound, uppder_bound)
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

#define MAX 500001

int answer[MAX];
vector<int> seok;
vector<int> jong;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, h;
    cin>>n>>h;
    
    for(int i=1; i<=n; i++) {
        int temp; cin>>temp;
        
        if(i % 2) seok.push_back(temp);
        else jong.push_back(temp);
    }
    
    sort(seok.begin(), seok.end());
    sort(jong.begin(), jong.end());
    
    /*
      lower_bound = 찾고자 하는 값 이상이 처음으로 나타나는 위치
      upper_bound = 찾고자 하는 값 초과가 처음으로 나타나는 위치
     */
    
    int min = n;
    int cnt = 0;
    
    for(int i=1; i<=h; i++) {
        int down = seok.size() - (lower_bound(seok.begin(), seok.end(), i) - seok.begin());
        int up = jong.size() - (lower_bound(jong.begin(), jong.end(), h-i+1) - jong.begin());
        
        int total = down + up;
        if(total == min) cnt += 1;
        else if(total < min) {
            min = total;
            cnt = 1;
        }
    }
    
    cout<<min<<' '<<cnt<<'\n';
    return 0;
}

