// 숫자야구 : 2차원 배열 활용
import java.util.*;

class Solution {
    private int answer;

    public boolean check(String num) {
        HashMap<String, Integer> hm = new HashMap<>();
        for(int i=0; i<num.length(); i++) {
            if(num.charAt(i) - '0' == 0)
                return false;
            String now = String.valueOf(num.charAt(i));
            if(hm.get(now) == null)
                hm.put(now, 1);
            else return false;
        }
        return true;
    }

    public void query(int[][] baseball, String num) {
        boolean flag = true;
        for(int i=0; i<baseball.length; i++) {
            String now = String.valueOf(baseball[i][0]);
            int strike = 0;
            int ball = 0;
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    if(num.charAt(j) == now.charAt(k)) {
                        if(j==k) strike += 1;
                        else ball += 1;
                    }
                }
            }
            if(strike != baseball[i][1] || ball != baseball[i][2])
                flag = false;
        }
        if(flag) this.answer += 1;
    }

    public int solution(int[][] baseball) {
        answer = 0;
        for(int i=123; i<=987; i++) {
            String num = String.valueOf(i);
            if(check(num))
                query(baseball, num);
        }
        return this.answer;
    }
}