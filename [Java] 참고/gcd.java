class Solution {

    public int gcd(int a, int b) {
        while(b != 0) {
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        int GCD = gcd(n, m);
        answer[0] = GCD;
        answer[1] = n * m / GCD;

        return answer;
    }

}