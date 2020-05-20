// 실패율 : 정렬
import java.util.*;

class Game {
    int stage;
    double fail;
    public Game(int stage, double fail) {
        this.stage = stage;
        this.fail = fail;
    }
}

class Solution {

    private int[] answer;
    private HashMap<Integer, Integer> map;
    private ArrayList<Game> list;
    private Comparator<Game> cmp;

    public void init(int N) {
        answer = new int[N];
        map = new HashMap<>();
        list = new ArrayList<>();
        cmp = new Comparator<>(){
            @Override
            public int compare(Game o1, Game o2) {
                if(o1.fail == o2.fail)
                    return o1.stage - o2.stage;
                else
                    return o1.fail - o2.fail < 0 ? 1 : -1;
            }
        };
    }

    public int[] solution(int N, int[] stages) {
        init(N);

        for(int i=0; i<stages.length; i++) {
            int cnt = map.getOrDefault(stages[i], 0);
            map.put(stages[i], cnt + 1);
        }

        int cleared = 0;
        for(int i=N+1; i>1; i--) {
            cleared += map.getOrDefault(i, 0);
            int trial = map.getOrDefault(i-1, 0);

            double fail;
            if(trial==0 || trial+cleared==0) fail = 0;
            else fail = (double) trial / (trial+cleared);

            Game game = new Game(i-1, fail);
            list.add(game);
        }

        Collections.sort(list, cmp);
        for(int i=0; i<list.size(); i++)
            answer[i] = list.get(i).stage;

        return answer;
    }

}