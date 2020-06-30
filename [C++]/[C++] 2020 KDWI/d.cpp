// 호텔 방 배정 : Disjoint Set
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;

/*
 매 방 요청마다 기록된 빈 방 번호를 찾지 않는게 핵심
 (1 : 2) -> (2 : 3) -> (3 : 4)
 이런식의 탐색을 반복하지 않기 위해
 (1 : 4) -> (2 : 4) -> (3 : 4)
 이런 구조 생성
 */
unordered_map<ll, ll> m;
ll find(ll target) {
    if(!m[target]) return target;
    return m[target] = find(m[target]);
}

vector<ll> solution(ll k, vector<ll> room) {
    vector<ll> answer;
    for(int i=0; i<room.size(); i++) {
        ll target = room[i];
        if(!m[target]) {
            answer.push_back(target);
            m[target] = find(target+1);
        }
        else {
            ll temp = find(target);
            answer.push_back(temp);
            m[temp] = find(temp+1);
        }
    }
    return answer;
}
