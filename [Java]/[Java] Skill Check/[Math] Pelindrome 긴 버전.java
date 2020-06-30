class Solution
{
    public int solution(String s)
    {
        int answer = 1;
        int len = s.length();
        for(int i=0; i<len ; i++) {
            int cnt = 1;
            int j = 1;
            while(true) {
                int left = i-j;
                int right = i+j;
                if(0<=left && right<len && s.charAt(left)==s.charAt(right)) {
                    cnt += 2;
                    j += 1;
                } else {
                    break;
                }
            }
            if(cnt > answer)
                answer = cnt;

            cnt = 0;
            j = 0;
            while(true) {
                int left = i-j;
                int right = i+j+1;
                if(0<=left && right<len && s.charAt(left)==s.charAt(right)) {
                    cnt += 2;
                    j += 1;
                } else {
                    break;
                }
            }
            if(cnt > answer)
                answer = cnt;
        }

        return answer;
    }
}