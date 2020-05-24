import java.util.*;

class Solution {
    public String solution(String s, int n) {
        String upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String lower = upper.toLowerCase();

        String answer = "";
        int len = s.length();
        for(int i=0; i<len; i++) {
            char temp = s.charAt(i);
            int idx;
            // 대문자
            if('A' <= temp && temp <= 'Z') {
                idx = upper.indexOf(temp);
                idx = (idx + n) % 26;
                temp = upper.charAt(idx);
            }
            // 소문자 
            if('a' <= temp && temp <= 'z') {
                idx = lower.indexOf(temp);
                idx = (idx + n) % 26;
                temp = lower.charAt(idx);
            }
            answer += temp;
        }
        return answer;
    }
}




