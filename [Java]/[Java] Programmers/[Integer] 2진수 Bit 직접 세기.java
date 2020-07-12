class Solution {

    public int countOne(int n) {
        int cnt = 0;
        while(n > 0) {
            if(n % 2 == 1) cnt += 1;
            n /= 2;
        }
        return cnt;
    }

    public int solution(int n) {
        int answer = 0;

        int ones = countOne(n);
        while(true) {
            int next = countOne(++n);
            if(next == ones) {
                answer = n;
                break;
            }
        }

        return answer;
    }
}