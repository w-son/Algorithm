// H-Index : 그냥 구현
import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int len = citations.length;
        for(int h=10000; h>=0; h--) {
            int cnt = 0;
            for(int i=0; i<len; i++)
                if(citations[i] >= h) cnt++;

            if(cnt >= h && len-cnt <= h) {
                answer = h;
                break;
            }
        }
        return answer;
    }
}