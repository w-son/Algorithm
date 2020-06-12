class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];

        for(int i=0; i<n; i++) {
            int now = arr1[i] | arr2[i];
            int num = 1;
            String temp = "";
            for(int j=0; j<n; j++) {
                if((now | num)  == now) temp += '#';
                else temp += ' ';

                num *= 2;
            }

            answer[i] = new StringBuilder(temp).reverse().toString();
        }

        return answer;
    }
}