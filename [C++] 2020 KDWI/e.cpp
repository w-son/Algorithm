// 징검다리 건너기 : 이분 탐색
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool test(vector<int>& stones, int k, int mid) {
    int cnt = 0;
    for(int i=0; i<stones.size(); i++) {
        if(stones[i] <= mid) {
            cnt += 1;
            if(cnt >= k)
                return true;
        }
        else
            cnt = 0;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1; int right = 200000000;
    int mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        bool check = test(stones, k, mid);
        if(check) {
            answer = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return answer;
}
