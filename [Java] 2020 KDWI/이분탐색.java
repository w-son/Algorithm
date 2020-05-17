// 징검다리 건너기 : 이분탐색
import java.util.*;

class Solution {

    public boolean cross(int[] stones, int k, int friends) {
        int cnt = 0;
        int len = stones.length;
        for(int i=0; i<len; i++) {
            if(stones[i] - friends <= 0)
                cnt += 1;
            else cnt = 0;
            if(cnt == k)
                return false;
        }
        return true;
    }

    public int solution(int[] stones, int k) {
        int answer = 0;

        int left = 1;
        int right = 0;
        for(int i=0; i<stones.length; i++)
            if(right < stones[i]) right = stones[i];

        while(left <= right) {
            int mid = (left + right) / 2;
            if(cross(stones, k, mid))
                left = mid + 1;
            else {
                answer = mid;
                right = mid - 1;
            }
        }
        return answer;
    }
}