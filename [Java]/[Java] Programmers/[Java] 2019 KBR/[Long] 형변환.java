// 무지의 먹방 라이브 : 정렬, long 형변환
import java.util.*;

class Food {
    int idx;
    int cnt;
    public Food(int idx, int cnt) {
        this.idx = idx;
        this.cnt = cnt;
    }
}

class Solution {
    private int answer;
    private ArrayList<Food> l1;
    private ArrayList<Food> l2;
    private Comparator<Food> c1;
    private Comparator<Food> c2;

    public void init() {
        this.answer = 0;
        this.l1 = new ArrayList<>();
        this.l2 = new ArrayList<>();
        this.c1 = new Comparator<Food>() {
            @Override
            public int compare(Food o1, Food o2) {
                if(o1.cnt == o2.cnt) return o1.idx - o2.idx;
                else return o1.cnt - o2.cnt;
            }
        };
        this.c2 = new Comparator<Food>() {
            @Override
            public int compare(Food o1, Food o2) {
                return o1.idx - o2.idx;
            }
        };
    }

    public int solution(int[] food_times, long k) {
        init();

        for(int i=0; i<food_times.length; i++)
            l1.add(new Food(i, food_times[i]));
        Collections.sort(l1, c1);

        int i;
        int len = l1.size();
        long total = 0;
        int prev = 0;
        for(i=0; i<len; i++) {
            Food now = l1.get(i);
            long next = (long)(len - i) * (now.cnt - prev);
            if(total + next <= k) {
                total += next;
                prev = now.cnt;
            } else
                break;
        }
        for(; i<len; i++)
            l2.add(l1.get(i));
        Collections.sort(l2, c2);

        if(l2.size() == 0) answer = -1;
        else {
            int num = (int)((k - total) % l2.size());
            answer = l2.get(num).idx + 1;
        }
        return answer;
    }
}