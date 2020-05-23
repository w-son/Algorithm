// 블록 게임 : 구현
import java.util.*;

class Solution {

    private int answer;
    private int len;
    private int[][] board;

    public void init(int[][] input) {
        this.answer = 0;
        this.len = input.length;
        this.board = input;
    }

    public boolean checkVertical(int x, int y) {
        for(int i=x-1; i>=0; i--)
            if(board[i][y] != 0)
                return false;
        return true;
    }

    public boolean checkGaro(int x, int y) {
        // 검은 블럭이 떨어질 수 없는 구조인지 확인
        if(board[x][y] != 0 && board[x][y+2] != 0) return false;

        int num = board[x+1][y];
        int cnt = 0;
        for(int i=x; i<x+2; i++) {
            for(int j=y; j<y+3; j++) {
                // 다른 색이 섞여 있는지, 0일시 수직 위로 블럭이 존재하는지 확인
                if(board[i][j]!=0 && board[i][j]!=num) return false;
                if(board[i][j]==num) cnt+=1;
                if(board[i][j]==0 && !checkVertical(i, j)) return false;
            }
        }
        if(cnt != 4) return false;

        for(int i=x; i<x+2; i++)
            for(int j=y; j<y+3; j++)
                board[i][j] = 0;

        this.answer += 1;
        return true;
    }

    public boolean checkSero(int x, int y) {
        // 검은 블록이 떨어질 수 없는 구조인지 확인
        if(board[x][y] != 0 && board[x][y+1] != 0) return false;

        int num = board[x+2][y];
        int cnt = 0;
        for(int i=x; i<x+3; i++) {
            for(int j=y; j<y+2; j++) {
                // 다른 색이 섞여 있는지, 0일시 수직 위로 블럭이 존재하는지 확인
                if(board[i][j]!=0&&board[i][j]!=num) return false;
                if(board[i][j]==num) cnt += 1;
                if(board[i][j]==0 && !checkVertical(i, j)) return false;
            }
        }
        if(cnt != 4) return false;

        for(int i=x; i<x+3; i++)
            for(int j=y; j<y+2; j++)
                board[i][j] = 0;

        this.answer += 1;
        return true;
    }

    public int solution(int[][] input) {
        init(input);

        boolean flag = true;
        while(flag) {
            flag = false;
            for(int i=0; i<len; i++) {
                for(int j=0; j<len; j++) {
                    if(i<len-1 && j<len-2)
                        if(checkGaro(i, j)) flag = true;
                    if(i<len-2 && j<len-1)
                        if(checkSero(i, j)) flag = true;
                }
            }
        }

        return answer;
    }
}