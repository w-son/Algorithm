import java.util.*;

class Solution {

    private int idx;
    private String str;

    public String make() {
        int num = 0;
        String ret = "";

        while(idx < str.length()) {
            char now = str.charAt(idx);
            if(Character.isDigit(now)) {
                num *= 10;
                num += now - '0';
                idx ++;
            }
            else if(now == '(') {
                idx ++;
                String repeat = make();
                for(int i=0; i<num; i++)
                    ret += repeat;

                num = 0;
            }
            else if(now == ')') {
                idx ++;
                break;
            }
            else {
                ret += now;
                idx ++;
            }
        }
        return ret;
    }

    public String[] solution(String compressed) {
        idx = 0;
        str = compressed;
        String answer = make();
        return answer;
    }
}