// 디스크 컨트롤러 : 우선순위 큐
import java.util.*;

class Job {
    int start;
    int duration;

    public Job(int start, int duration) {
        this.start = start;
        this.duration = duration;
    }
}

class Solution {

    private int answer;
    private int time;
    private ArrayList<Job> al;
    private PriorityQueue<Job> pq;
    private Comparator<Job> cmp;

    public void init() {
        this.answer = 0;
        this.time = 0;
        this.al = new ArrayList<>();
        this.cmp = new Comparator<Job>() {
            @Override
            public int compare(Job o1, Job o2) {
                if(o1.start == o2.start)
                    return o1.duration - o2.duration;
                else
                    return o1.start - o2.start;
            }
        };
        this.pq = new PriorityQueue<>(new Comparator<Job>(){
            @Override
            public int compare(Job o1, Job o2) {
                return o1.duration - o2.duration;
            }
        });
    }

    public int solution(int[][] jobs) {
        init();

        int idx = 0;
        int len = jobs.length;
        for(int i=0; i<len; i++)
            al.add(new Job(jobs[i][0], jobs[i][1]));
        Collections.sort(al, cmp);

        while(true) {
            while(idx < len && time >= al.get(idx).start)
                pq.offer(al.get(idx++));

            // 작업을 수행하고 있지 않은 경우에
            if(pq.isEmpty()) {
                if(idx == len)
                    break;

                time = al.get(idx).start;
                pq.offer(al.get(idx++));
            }

            Job now = pq.poll();
            System.out.println(now.start);
            System.out.println(now.duration);
            time += now.duration;
            answer += time - now.start;
        }

        return answer / len;
    }
}