import java.util.*;

class Solution {

    /*
        try hello world
        TrY HeLlO WoRlD
        이렇게 변환하기
    */

    public String solution(String s) {
        String answer = "";

        int cnt = 0;
        String[] arr = s.split("");
        for(String tmp : arr) {
            cnt = tmp.contains(" ") ? 0 : cnt + 1;
            answer += cnt%2 == 0 ? tmp.toLowerCase() : tmp.toUpperCase();
        }

        return answer;
    }
}