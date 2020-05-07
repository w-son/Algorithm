// 가장 큰 수 : 정렬 Comparator
import java.util.*;

class Solution {

    public String solution(int[] numbers) {
        ArrayList<String> list = new ArrayList<>();

        int len = numbers.length;
        for(int i=0; i<len; i++)
            list.add(Integer.toString(numbers[i]));

        Comparator<String> cmp = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2 + o1).compareTo(o1 + o2);
            }
        };
        Collections.sort(list, cmp);

        String answer = "";
        boolean isZero = true;
        for(int i=0; i<len; i++) {
            String temp = list.get(i);
            if(!temp.equals("0"))
                isZero = false;
            answer += list.get(i);
        }
        if(isZero)
            answer = "0";
        return answer;
    }

}