/*
 String 형태의 permutation
 String을 정렬함으로서 Map에 사용될 키값(카카오프렌즈 2명 이니셜)을 정하고
 키값에 해당하는 범위(원하는 거리의 최대 최소, '='일 경우 start, end를 숫자로 둔다)를 갱신

 -> 모든 조합에 대해서 Map의 모든 키값에 해당하는 범위를 구한다
 */
import java.util.*;

class Solution {

    private int answer;
    private Map<String, Range> map;

    public class Range {
        private int start;
        private int end;

        public Range(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public boolean parse(String data) {

        // 원하는 입력 조건을 구하는 로직
        String[] temp = data.split("");
        String[] friends = new String[] { temp[0], temp[2] };
        Arrays.sort(friends);

        String key = String.join("", friends);
        String eq = temp[3];
        Integer num = Integer.parseInt(temp[4]);

        int min = Integer.MIN_VALUE;
        int max = Integer.MAX_VALUE;
        Range range = map.getOrDefault(key, new Range(min, max));
        Range request = null;

        if(eq.equals("=")) request = new Range(num, num);
        else if(eq.equals("<")) request = new Range(min, num-1);
        else request = new Range(num+1, max);

        if(range.end < request.start || range.start > request.end)
            return false;

        request.start = Math.max(range.start, request.start);
        request.end = Math.min(range.end, request.end);
        map.put(key, request);

        return true;
    }

    public void perm(String now, String rem) {
        if(rem.equals("")) {

            // 지금 순서가 친구들이 원하는 기준에 모두 맞는지 확인
            boolean flag = true;

            for(String key : map.keySet()) {
                Range range = map.get(key);

                int left = now.indexOf(key.charAt(0));
                int right = now.indexOf(key.charAt(1));
                int dist = Math.abs(left - right) - 1;

                if(dist < range.start || dist > range.end) {
                    flag = false;
                    break;
                }
            }

            if(flag) answer += 1;
        }

        else {
            // 카카오 프렌즈 줄세우기 모든 경우의 수
            int len = rem.length();
            for(int i=0; i<len; i++) {
                String next = now + rem.charAt(i);
                perm(next, rem.substring(0, i) + rem.substring(i+1, len));
            }

        }
    }

    public int solution(int n, String[] data) {
        this.answer = 0;
        this.map = new HashMap<>();

        for(String string : data) {
            if(!parse(string))
                return answer;
        }

        String kakao = "ACFJMNRT";
        perm("", kakao);

        return answer;
    }
}