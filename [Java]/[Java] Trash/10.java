// 위장 : 해시맵, 계산
import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, Integer> map = new HashMap<>();

        int len = clothes.length;
        for(int i=0; i<len; i++) {
            String wear = clothes[i][1];
            map.put(wear, map.getOrDefault(wear, 0) + 1);
        }

        int answer = 1;
        for(String key : map.keySet())
            answer *= map.get(key) + 1;
        return answer - 1;
    }
}