// 전화번호 목록 : 해시맵
import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        HashMap<String, Integer> map = new HashMap<>();

        boolean answer = true;
        int len = phone_book.length;
        for(int i=0; i<len; i++) {
            String now = phone_book[i];
            map.put(now, 1);
            int size = now.length();
            for(int j=1; j<size; j++) {
                String sub = now.substring(0, j);
                int search = map.getOrDefault(sub, 0);
                if(search == 1) {
                    answer = false;
                    break;
                }
            }
            if(!answer)
                break;
        }

        return answer;
    }
}