import java.util.*;

class Solution {
    public String solution(String s, int n) {
        String answer = "";

        for(int i=0; i<s.length(); i++) {

            char now = s.charAt(i);
            if(Character.isAlphabetic(now)) {

                if('A' <= now && now <= 'Z') {
                    int next = (now - 'A' + n) % 26;
                    now = (char)('A' + next);
                }

                if('a' <= now && now <= 'z') {
                    int next = (now - 'a' + n) % 26;
                    now = (char)('a' + next);
                }
            }
            answer += now;
        }

        return answer;
    }
}