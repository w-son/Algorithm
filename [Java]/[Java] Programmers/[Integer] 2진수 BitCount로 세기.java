class Solution {

    public int solution(int n) {

        int answer = 0;
        int ones = Integer.bitCount(n);

        while(true) {
            int next = Integer.bitCount(++n);
            if(next == ones) {
                answer = n;
                break;
            }
        }

        return answer;
    }
}