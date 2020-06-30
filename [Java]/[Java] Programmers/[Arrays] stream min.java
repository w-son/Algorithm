import java.util.*;

class Solution {
    public int[] solution(int[] arr) {

        int min = Arrays.stream(arr).min().getAsInt();

        int[] answer;
        if(arr.length == 1) {
            answer = new int[]{-1};
        } else {
            answer = new int[arr.length-1];
            int idx = 0;
            for(int i=0; i<arr.length; i++)
                if(arr[i] != min) answer[idx++] = arr[i];
        }

        return answer;
    }
}