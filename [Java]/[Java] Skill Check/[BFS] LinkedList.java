import java.util.*;

class Solution {
    private int num;
    private int answer;
    private HashMap<Integer, ArrayList<Integer>> O;
    private HashMap<Integer, ArrayList<Integer>> R;

    public boolean check(int start) {
        HashSet<Integer> set = new HashSet<>();
        LinkedList<Integer> queue = new LinkedList<>();

        set.add(start);
        queue.push(start);
        while(!queue.isEmpty()) {
            int front = queue.pop();
            ArrayList<Integer> list = O.get(front);
            for(Integer i : list)
                if(set.add(i)) queue.push(i);
        }

        queue.push(start);
        while(!queue.isEmpty()) {
            int front = queue.pop();
            ArrayList<Integer> list = R.get(front);
            for(Integer i : list)
                if(set.add(i)) queue.push(i);
        }

        boolean flag = true;
        for(int i=1; i<=num; i++)
            if(set.add(i)) flag = false;

        return flag;
    }

    public int solution(int n, int[][] results) {
        this.answer = 0;
        this.num = n;
        O = new HashMap<>();
        R = new HashMap<>();

        for(int i=1; i<=n; i++) {
            O.put(i, new ArrayList<Integer>());
            R.put(i, new ArrayList<Integer>());
        }

        for(int i=0; i<results.length; i++) {
            int win = results[i][0];
            int lose = results[i][1];

            ArrayList<Integer> x = O.get(lose);
            ArrayList<Integer> y = R.get(win);
            x.add(win);
            y.add(lose);

            O.put(lose, x);
            R.put(win, y);
        }

        for(int i=1; i<=num; i++)
            if(check(i)) answer += 1;

        return answer;
    }
}