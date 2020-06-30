// 카펫 : 완전탐색
import java.util.*;

class Solution {
    public int[] solution(int brown, int red) {
        int[] answer = new int[2];
        for(int i=red; i>=1; i--) {
            if(red%i==0 && (i+2)*(red/i+2)-red==brown) {
                answer[0] = i + 2;
                answer[1] = red/i + 2;
                break;
            }
        }
        return answer;
    }
}