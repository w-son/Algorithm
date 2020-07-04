class Solution {

    public String solution(String number, int k) {
        StringBuilder answer = new StringBuilder(number);

        /*
         문자열을 앞에서 부터 읽으면서
         j, j + 1
         비교해서 j쪽이 낮다면 j를 없앤다
         = 가장 큰 숫자 생성
         * 그러한 구조가 없다면 맨 마지막 숫자를 제거
         */


        for(int i=0; i<k; i++) {

            int len = answer.length();
            int target = len-1;

            for(int j=0; j<target; j++) {
                if(answer.charAt(j) < answer.charAt(j+1)) {
                    target = j;
                    break;
                }
            }

            answer.deleteCharAt(target);
        }

        return answer.toString();
    }

}