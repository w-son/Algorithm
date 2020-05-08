// 완주하지 못한 선수 : 해시맵
import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> hm = new HashMap<>();
        for(int i=0; i<participant.length; i++)
            hm.put(participant[i], hm.getOrDefault(participant[i], 0)+1);
        for(int i=0; i<completion.length; i++)
            hm.put(completion[i], hm.get(completion[i])-1);

        String answer = "";
        for(String key : hm.keySet()) {
            if(!hm.get(key).equals(0)) {
                answer = key;
                break;
            }
        }
        return answer;
    }
}