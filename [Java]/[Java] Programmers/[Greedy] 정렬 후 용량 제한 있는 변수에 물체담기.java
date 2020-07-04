import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;

        Arrays.sort(people);
        int start = 0;
        int end = people.length - 1;

        /*
         정렬 한 다음에
         작은거 + 큰거
         의 결과가 용량 제한에 넘는지 확인 한 다음에
         넘으면 큰거만 빼고 그렇지 않으면 둘다 뺌
         */
        while(start <= end) {
            int small = people[start];
            int big = people[end];

            if(start == end) {
                answer += 1;
                break;
            }
            if(small + big > limit) {
                end -= 1;
                answer += 1;
            } else {
                start += 1;
                end -= 1;
                answer += 1;
            }
        }

        return answer;
    }
}