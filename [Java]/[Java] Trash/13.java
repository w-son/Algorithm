// 단언 변환 : BFS, String 비교는 equals로
import java.util.*;

class word {
    String str;
    int cnt;
    public word(String str, int cnt) {
        this.str = str;
        this.cnt = cnt;
    }
}

class Solution {

    private HashMap<String, Integer> map;
    private LinkedList<word> queue;

    private void init() {
        this.map = new HashMap<>();
        this.queue = new LinkedList<>();
    }

    public int solution(String begin, String target, String[] words) {
        // 초기화
        init();

        int answer = 0;
        int len = words.length;
        int size = begin.length();
        word start = new word(begin, 0);
        queue.push(start);

        while(queue.isEmpty() == false) {
            word now = queue.pop();

            if(now.str.equals(target)) {
                if(answer == 0 || now.cnt < answer)
                    answer = now.cnt;
            }

            for(int i=0; i<len; i++) {
                String next = words[i];
                int check = map.getOrDefault(next, -1);

                if(check == -1) {
                    int count = 0;
                    for(int j=0; j<size; j++)
                        if(now.str.charAt(j) != next.charAt(j))
                            count++;

                    if(count == 1) {
                        map.put(next, 1);
                        word changed = new word(next, now.cnt + 1);
                        queue.push(changed);
                    }
                }
            }
        }

        return answer;
    }
}