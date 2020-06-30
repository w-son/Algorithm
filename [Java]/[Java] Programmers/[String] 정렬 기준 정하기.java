import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings, new Comparator<String>() {
            // -1 을 리턴하면 o1이 앞으로 간다
            @Override
            public int compare(String o1, String o2) {
                if(o1.charAt(n) == o2.charAt(n))
                    return o1.compareTo(o2);
                else
                    return o1.charAt(n) < o2.charAt(n) ? -1 : 1;
            }
        });

        return strings;
    }
}