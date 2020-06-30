// 더 맵게 : 우선순위 큐, Comparator
import java.util.*;

class Solution {

    private int answer;
    private PriorityQueue<Integer> pq;

    public void init() {
        this.answer = 0;
        this.pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });
    }

    public int solution(int[] scoville, int K) {
        init();

        int len = scoville.length;
        for(int i=0; i<len; i++)
            pq.offer(scoville[i]);

        while(true) {
            int a = pq.poll(); // 확인만 하는 경우 peek
            if(a >= K)
                break;
            if(a < K && pq.isEmpty()) {
                answer = -1;
                break;
            }
            int b = pq.poll();
            int mixed = a + 2 * b;
            pq.offer(mixed);
            answer += 1;
        }

        return answer;
    }
}