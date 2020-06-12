import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {

        int len = progresses.length;
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<len; i++) {
            int a = 100 - progresses[i];
            int b = speeds[i];
            queue.add(a%b==0 ? a/b : a/b+1);
        }

        int cnt = 0;
        List<Integer> answer = new ArrayList<>();
        while(!queue.isEmpty()) {
            int now = queue.poll();
            cnt += 1;
            while(!queue.isEmpty() && queue.peek() <= now) {
                queue.poll();
                cnt += 1;
            }
            answer.add(cnt);
            cnt = 0;
        }

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}