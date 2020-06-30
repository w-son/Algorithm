import java.util.*;

class Solution {
    public String solution(String[] seoul) {

        int idx = Arrays.asList(seoul).indexOf("Kim");

        return "김서방은 " + Integer.toString(idx) + "에 있다";

        // 없을 경우 리턴값 -1
    }
}