import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {

        Queue<Integer> wait = new LinkedList<>();
        Queue<Integer> move = new LinkedList<>();
        for(int i=0; i<truck_weights.length; i++)
            wait.add(truck_weights[i]);
        for(int i=0; i<bridge_length; i++)
            move.add(0);

        int answer = 1;
        int total = wait.poll();
        move.poll();
        move.add(total);

        while(!move.isEmpty()) {

            if(!wait.isEmpty()) {
                int truck = wait.peek();
                total -= move.poll();
                answer += 1;

                if(total + truck <= weight) {
                    total += truck;
                    move.add(wait.poll());
                }
                else
                    move.add(0);
            }

            else {
                move.poll();
                answer += 1;
            }
        }

        return answer;
    }
}