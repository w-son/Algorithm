// 튜플 : replace, split, trim, HashSet, 람다표현식
import java.util.*;

class Solution {
    private int[] answer;
    private HashSet<String> set;

    public void init(int len) {
        this.answer = new int[len];
        this.set = new HashSet<>();
    }

    public int[] solution(String s) {
        // String 의 여러 메서드들 활용 방법
        String[] arr = s.replaceAll("[{]", " ").replaceAll("[}]", " ")
                .trim().split(" , ");
        // 람다식을 통한 정렬
        Arrays.sort(arr, (o1, o2) -> {return o1.length() - o2.length();} );

        int idx = 0;
        init(arr.length);
        for(String str : arr) {
            for(String num : str.split(","))
                if(set.add(num)) answer[idx++] = Integer.parseInt(num);
        }

        return answer;
    }
}