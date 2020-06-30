import java.util.*;

class Solution {

    class Number {
        int idx;
        int cnt;

        public Number(int idx, int cnt) {
            this.idx = idx;
            this.cnt = cnt;
        }
    }

    public int solution(int[] numbers, int target) {
        int answer = 0;

        Queue<Number> queue = new LinkedList<>();
        queue.add(new Number(0, numbers[0]));
        queue.add(new Number(0, -numbers[0]));

        while(!queue.isEmpty()) {
            Number now = queue.poll();
            if(now.idx == numbers.length - 1) {
                if(now.cnt == target)
                    answer += 1;
            }
            else {
                int nextIdx = now.idx + 1;
                int nextNum = numbers[nextIdx];
                queue.add(new Number(nextIdx, now.cnt + nextNum));
                queue.add(new Number(nextIdx, now.cnt - nextNum));
            }
        }

        return answer;
    }
}