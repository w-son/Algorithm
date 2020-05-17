// 크레인 인형 뽑기 게임 : 구현, Stack
import java.util.*;

class Solution {

    private int answer;
    private int len;
    private Stack<Integer> stack;
    private int[][] board;

    public void init(int[][] b) {
        this.answer = 0;
        this.len = b.length;
        this.stack = new Stack<Integer>();
        this. board = b;
    }

    // 인형 뽑기
    public int getDoll(int col) {
        int doll = 0;
        for(int i=0; i<this.len; i++)
            if(this.board[i][col] > 0) {
                doll = this.board[i][col];
                this.board[i][col] = 0;
                break;
            }
        return doll;
    }

    // 뽑은 인형 바구니에 담기
    public void dropDoll(int doll) {
        if(!this.stack.isEmpty() && this.stack.peek() == doll) {
            this.stack.pop();
            this.answer += 2;
        }
        else this.stack.push(doll);
        return;
    }

    public int solution(int[][] b, int[] m) {
        init(b);
        for(int i=0; i<m.length; i++) {
            int doll = getDoll(m[i] - 1);
            if(doll != 0) dropDoll(doll);
        }
        return answer;
    }
}