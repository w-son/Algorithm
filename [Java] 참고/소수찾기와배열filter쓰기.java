import java.util.*;

class Solution {
    public int solution(int n) {

        // 에라토스테네스의 채
        int[] arr = new int[n+1];
        arr[0] = arr[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=i+i; j<=n; j+=i)
                arr[j] = 1;
        }

        return Arrays.stream(arr).filter(x -> x==0).toArray().length;
    }
}