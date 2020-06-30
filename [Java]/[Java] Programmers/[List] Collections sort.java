import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<arr.length; i++)
            if(arr[i]%divisor == 0)
                list.add(arr[i]);
        Collections.sort(list, (i, j) -> { return i - j; });

        int len = list.size();
        int[] answer;
        if(len == 0) {
            answer = new int[1];
            answer[0] = -1;
        } else {
            answer = new int[len];
            for(int i=0; i<len; i++)
                answer[i] = list.get(i);
        }
        return answer;
    }
}