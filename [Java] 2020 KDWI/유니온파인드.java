// 호텔 방 배정 : 유니온 파인드
import java.util.*;

class Solution {

    private int len;
    private HashMap<Long, Long> room;
    private long[] answer;

    public void init(int len) {
        this.len = len;
        this.room = new HashMap<>();
        this.answer = new long[len];
    }

    public long find(long query) {
        long result = room.getOrDefault(query, (long)-1);
        if(result == -1) return query;
            // room[query] = find(room[query]);
        else {
            long temp = find(result);
            room.put(query, temp);
            return temp;
        }
    }

    public long[] solution(long k, long[] room_number) {
        init(room_number.length);

        int idx = 0;
        for(int i=0; i<len; i++) {
            long query = room_number[i];
            long result = room.getOrDefault(query, (long)-1);

            if(result == -1)
                answer[idx] = query; // 방이 비어 있는 경우
            else
                answer[idx] = find(query); // 다른 방을 사용해야 하는 경우

            long next = find(answer[idx] + 1);
            room.put(answer[idx++], next);
        }
        return answer;
    }
}