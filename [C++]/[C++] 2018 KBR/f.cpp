// 프렌즈4블록 : 문자열, 배열 처리
#include <string>
#include <vector>
using namespace std;

int answer = 0;
int cx[3] = {1, 1, 0};
int cy[3] = {0, 1, 1};

// 블럭이 지워진 이후 기존의 블럭들이 내려오는 것들을 처리
void fall_down(int x, int y, vector<string>& board) {
    if(board[x][y] != '?') return;
    // x,y 기준으로 수직 위로 '?' 가 아닌 문자가 있는지 탐색
    for(int i=x; i>=0; i--) {
        if(board[i][y] != '?') {
            char temp = board[i][y];
            board[i][y] = '?';
            board[x][y] = temp;
            break;
        }
    }
}

// x, y 기준으로 현재 블럭이 지워지는지 확인 후 처리
bool try_pop(int x, int y, vector<string>& board) {
    char now = board[x][y];
    if(now == '?') return false;
    for(int i=0; i<3; i++) {
        int mx = x + cx[i];
        int my = y + cy[i];
        if(board[mx][my] != now && board[mx][my] != now - 32)
            return false;
    }
    if(65<=now && now<=90) {
        board[x][y] += 32;
        answer += 1;
    }
    for(int i=0; i<3; i++) {
        int mx = x + cx[i];
        int my = y + cy[i];
        if(65<=board[mx][my] && board[mx][my]<=90) {
            board[mx][my] = board[x][y];
            answer += 1;
        }
    }
    return true;
}

// 게임 실행부
void friends_block(int m, int n, vector<string>& board) {

    // 더이상 지울 블럭이 없을 경우 -> flag가 false인 경우
    bool flag = true;
    
    while(flag) {
        flag = false;
        // 내려와야할 블럭들 처리
        for(int i=m-1; i>=0; i--)
            for(int j=0; j<n; j++)
                fall_down(i, j, board);
        // 지워질 블럭들 처리
        for(int i=0; i<m-1; i++)
            for(int j=0; j<n-1; j++) {
                bool pop = try_pop(i, j, board);
                if(pop) flag = true;
            }
        // 블럭을 지우고 난 후 지워진 블럭들에 한에서 '?' 처리
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(97<=board[i][j] && board[i][j]<=122)
                    board[i][j] = '?';
    }
    return;
}

int solution(int m, int n, vector<string> board) {
    friends_block(m, n, board);
    return answer;
}
