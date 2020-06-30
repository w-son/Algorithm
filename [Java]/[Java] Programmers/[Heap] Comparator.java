import java.util.*;

class Solution {

    public class Task {
        int idx;
        int pri;

        public Task(int idx, int pri) {
            this.idx = idx;
            this.pri = pri;
        }
    }

    public int solution(int[] priorities, int location) {
        int len = priorities.length;
        int answer = 0;

        Comparator<Integer> cmp = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 > o2 ? -1 : 1;
            }
        };
        Queue<Integer> pq = new PriorityQueue<>(cmp);
        Queue<Task> q = new LinkedList<>();
        for(int i=0; i<len; i++) {
            pq.offer(priorities[i]);
            q.add(new Task(i, priorities[i]));
        }

        int cnt = 1;
        while(true) {

            int top = pq.peek();
            Task front = q.poll();

            if(front.pri == top) {
                if(front.idx == location) {
                    answer = cnt;
                    break;
                }
                pq.poll();
                cnt += 1;
            }
            else
                q.add(front);
        }

        return answer;
    }
}