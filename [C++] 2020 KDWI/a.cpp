// 크레인 인형뽑기 게임 : 구현
#include <string>
#include <vector>
#include <stack>
using namespace std;

int n, answer;
stack<int> s;

int get(vector<vector<int>>& board, int move) {
    int num;
    for(int i=0; i<n; i++) {
        if(board[i][move]) {
            num = board[i][move];
            board[i][move] = 0;
            return num;
        }
    }
    return 0;
}

void push(int num) {
    if(!s.empty() && s.top() == num) {
        answer += 2;
        s.pop();
    }
    else {
        if(num)
            s.push(num);
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    n = board.size();
    answer = 0;
    for(int i=0; i<moves.size(); i++) {
        int num = get(board, moves[i]-1);
        push(num);
    }
    
    return answer;
}
