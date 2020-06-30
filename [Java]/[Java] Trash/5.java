// K번째 수 : 배열 정렬과 배열 복사
import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {

        int len = array.length;
        int cmds = commands.length;
        int[] answer = new int[cmds];

        for(int i=0; i<cmds; i++) {
            int[] temp = Arrays.copyOf(array, len);
            int start = commands[i][0]-1;
            int end = commands[i][1];
            Arrays.sort(temp, start, end);

            int idx = start + commands[i][2] - 1;
            answer[i] = temp[idx];
        }

        return answer;
    }
}