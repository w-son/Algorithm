class Solution {
    public String solution(int n) {

        String answer = "";

        while(true) {
            n -= 1;
            if(n < 0) break;

            int rem = (n%3);
            if(rem == 0) rem = 1;
            else if(rem == 1) rem = 2;
            else if(rem == 2) rem = 4;

            answer = Integer.toString(rem) + answer;
            n /= 3;
        }

        return answer;
    }
}