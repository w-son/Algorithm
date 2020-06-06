import java.util.*;

class Solution {

    private String answer;

    public long solution(long n) {
        answer = ""; // 지역변수를 forEach에 쓰면 final값이어야 되기 때문에 밖으로 뻈음

        Long.toString(n).chars().sorted().forEach(c -> answer = (char)c + answer);

        return Long.parseLong(answer);
    }
}