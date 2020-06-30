import java.util.*;

class Solution {

    public int compress(String s, int size) {

        int len = s.length();
        String ret = "";
        String prev = "";
        String now = "";
        int cnt = 1;

        for(int i=0; i<=len; i+=size) {

            int end = i+size > len ? len : i+size;
            now = s.substring(i, end);

            if(now.equals(prev)) {
                cnt += 1;
            } else {
                if(cnt != 1) ret += Integer.toString(cnt);
                ret += prev;
                prev = now;
                cnt = 1;
            }
        }
        if(cnt != 1) ret += Integer.toString(cnt);
        ret += now;

        return ret.length();
    }

    public int solution(String s) {

        int answer = Integer.MAX_VALUE;

        for(int i=1; i<=s.length(); i++) {
            int len = compress(s, i);
            if(len < answer) answer = len;
        }

        return answer;
    }
}