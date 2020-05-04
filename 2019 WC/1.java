// 멀쩡한 사각형 : Math
class Solution {
    public long solution(int w, int h) {
        long a = Math.min(w, h);
        long b = Math.max(w, h);
        long rem = 1;
        while(rem > 0) {
            rem = b % a;
            b = a;
            a = rem;
        }
        long answer = (long)w * (long)h - (long)(w + h - b);
        return answer;
    }
}