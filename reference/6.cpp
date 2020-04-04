// 11003 최솟값 찾기 : 슬라이딩 윈도우
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

int num[10000000];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l;
    cin>>n>>l;
    
    for(int i=0; i<n; i++)
        cin>>num[i];
    
    deque<int> dq;
    for(int i=0; i<n; i++) {
        // 윈도우의 구간에 해당하지 않는 원소를 앞에서 부터 뺀다
        while(!dq.empty() && dq.front() <= i-l)
            dq.pop_front();
        /*
          현제 덱 내의 원소 + 추가될 i 번째 원소 = 윈도우 크기
          덱의 뒤에서부터 i번쨰 원소보다 작은 원소들을 전부 뺀다
          연산 후 윈도우 내 원소가 오름차순으로 정렬 되어있다
          가장 작은 원소인 맨 앞 원소가 팝 되어도 그 다음으로 작은 원소가 front에 오게된다
         */
        while(!dq.empty() && num[dq.back()] >= num[i])
            dq.pop_back();
        
        dq.push_back(i);
        cout<<num[dq.front()]<<' ';
    }
    
    return 0;
}

