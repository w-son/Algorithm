// 오픈채팅방 : 문자열 파싱, 해시맵
import java.util.*;

class Solution {

    private String[] answer;
    private HashMap<String, String> map;

    public String[] solution(String[] record) {

        int len = 0;
        map = new HashMap<>();
        for(int i=0; i<record.length; i++) {
            String[] info = record[i].split(" ");
            if(!info[0].equals("Leave"))
                map.put(info[1], info[2]);
            if(!info[0].equals("Change"))
                len++;
        }

        int idx = 0;
        String[] answer = new String[len];
        for(int i=0; i<record.length; i++) {
            String[] info = record[i].split(" ");
            if(info[0].equals("Enter"))
                answer[idx++] = map.get(info[1]) + "님이 들어왔습니다.";
            if(info[0].equals("Leave"))
                answer[idx++] = map.get(info[1]) + "님이 나갔습니다.";
        }

        return answer;
    }
}