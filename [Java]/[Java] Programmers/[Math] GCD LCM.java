import java.util.*;

class Solution {

    public int gcd(int a, int b) {
        while(b > 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public int solution(int[] arr) {

        int answer = arr[0];

        for(int i=1; i<arr.length; i++) {
            int GCD = gcd(answer, arr[i]);
            int LCM = answer * arr[i] / GCD;
            answer = LCM;
        }

        return answer;
    }

}