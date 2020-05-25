import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {

        int[] answer = Arrays.stream(arr).filter(i -> i%divisor == 0).toArray();
        Arrays.sort(answer);

        if(answer.length == 0) {
            answer = new int[1];
            answer[0] = -1;
        }

        return answer;
    }
}