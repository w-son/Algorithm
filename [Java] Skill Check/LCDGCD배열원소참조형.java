// 최대공약수 최소공배수, 참조형은 클래스나 배열 전체를 넘겨야 되나봄
import java.util.*;

class Solution {

    public int gcd(int a, int b) {

        while(b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public int solution(int[] arr) {
        int answer = arr[0];
        int len = arr.length;

        for(int i=1; i<len; i++) {
            int a = answer;
            int b = arr[i];
            int GCD = gcd(a, b);
            answer = a * b / GCD;
        }

        return answer;
    }
}