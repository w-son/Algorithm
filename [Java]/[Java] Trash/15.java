// 라면공장 : 우선순위큐
import java.util.*;

class Solution {

    private int answer;
    private PriorityQueue<Integer> pq;

    public void init() {
        answer = 0;
        pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
    }

    public int solution(int stock, int[] dates, int[] supplies, int k) {
        init();

        int used = 0;
        int stored = stock;
        int idx = 0;
        int len = supplies.length;

        while(true) {
            used += stored;
            stored = 0;
            if(used >= k)
                break;

            while(idx < len && used >= dates[idx])
                pq.offer(supplies[idx++]);

            stored += pq.poll();
            answer += 1;
        }

        return answer;
    }
}