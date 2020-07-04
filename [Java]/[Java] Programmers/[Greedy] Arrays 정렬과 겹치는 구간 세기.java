import java.util.*;

class Solution {
    public int solution(int[][] routes) {

        int answer = 0;

        Arrays.sort(routes, (o1, o2) -> { return o1[1] - o2[1]; });

        // 포인트 : 제일 먼저 나가는 자동차 기준으로 거를 수 있을만큼 거른다

        int end = Integer.MIN_VALUE;

        for(int[] arr : routes) {
            if(end < arr[0]) {
                answer += 1;
                end = arr[1];
            }
        }

        return answer;
    }
}