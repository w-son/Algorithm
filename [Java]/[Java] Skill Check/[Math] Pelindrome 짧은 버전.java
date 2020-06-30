import java.util.*;

class Solution
{
    public int solution(String s)
    {
        int answer = 1;
        int len = s.length();

        String r = "";
        for(int i=len-1; i>=0; i--)
            r += s.charAt(i);

        for(int i=0; i<len; i++) {
            for(int j=i+1; j<=len; j++) {
                int temp = j-i;
                String a = s.substring(i, j);
                String b = r.substring(len-j, len-i);

                if(a.equals(b) && j-i > answer)
                    answer = j-i;
            }
        }

        return answer;
    }
}