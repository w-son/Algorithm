// 무지의 먹방 라이브 : sort 두번
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool cmp(pair<ll, int> a, pair<ll, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    
    vector<pair<ll, int>> v;
    for(int i=0; i<food_times.size(); i++)
        v.push_back({food_times[i], i+1});
    // 음식의 개수 기준으로 정렬
    sort(v.begin(), v.end());
    
    int len = food_times.size();
    int i;
    // 음식 개수가 적은 기준으로 k에서 차례로 뺀다
    for(i = 0 ; i < len; i++) {
        ll now = i == 0 ? v[i].first : v[i].first - v[i - 1].first;
        ll sum = now * (len - i);
        if(k - sum < 0) break;
        else k -= sum;
    }
    if (i == len) return -1;
    k %= (len - i);
    // 음식의 순서 기준으로 정렬
    sort(v.begin() + i, v.end(), cmp);
    return v[i + k].second;
    
}
