// 소수 찾기 : HashMap, NullPointerException
import java.util.*;

class Solution {

    private int MAX = 10000000;
    private int len;
    private int answer;
    private boolean[] prime;
    private HashMap<String, Integer> check;

    public void init(String num) {
        answer = 0;
        prime = new boolean[MAX];
        for(int i=2; i<MAX/2; i++)
            for(int j=i+i; j<MAX; j+=i)
                prime[j] = true;

        check = new HashMap<>();
        len = num.length();
        for(int i=0; i<len; i++) {
            String now = Character.toString(num.charAt(i));
            if(check.get(now) == null)
                check.put(now, 1);
            else
                check.put(now, check.get(now) + 1);
        }
    }

    public void find(String num) {
        boolean flag = true;
        HashMap<String, Integer> tmp = new HashMap<>();
        for(int i=0; i<num.length(); i++) {
            String now = Character.toString(num.charAt(i));
            if(this.check.get(now) == null)
                flag = false;
            else if(this.check.get(now) == tmp.get(now))
                flag = false;
            else {
                if(tmp.get(now) == null)
                    tmp.put(now, 1);
                else
                    tmp.put(now, tmp.get(now) + 1);
            }
        }
        if(flag)
            this.answer += 1;
    }

    public int solution(String numbers) {
        init(numbers);

        for(int i=2; i<MAX; i++) {
            if(!prime[i])
                find(String.valueOf(i));
        }
        return this.answer;
    }

}