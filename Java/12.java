// 네트워크 : BFS, LinkedList
import java.util.*;

class Solution {

    private int answer;
    private LinkedList<int[]> queue;
    private HashMap<Integer, Integer> map;

    private void init() {
        answer = 0;
        this.queue = new LinkedList<>();
        this.map = new HashMap<>();
    }

    public int solution(int n, int[][] computers) {
        init();

        for(int i=0; i<n; i++) {
            int find = map.getOrDefault(i, -1);

            if(find == -1) {
                map.put(i, 1);
                queue.push(computers[i]);

                while(queue.isEmpty() == false) {
                    int[] temp = queue.pop();
                    for(int j=0; j<n; j++) {
                        if(temp[j] == 1) {
                            int check = this.map.getOrDefault(j, -1);
                            if(check == -1) {
                                map.put(j, 1);
                                queue.push(computers[j]);
                            }
                        }
                    }
                }
                this.answer += 1;
            }
        }
        return this.answer;
    }
}