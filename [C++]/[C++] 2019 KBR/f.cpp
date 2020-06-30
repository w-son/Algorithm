// 블록게임 : 시뮬레이션
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string garo_block[3] = { "100111", "001111", "010111" };
string sero_block[3] = { "010111", "101011", "" };

unordered_map<string, int> garo_map;
unordered_map<string, int> sero_map;

int answer = 0;

bool check_garo(vector<vector<int>>& board, int x, int y) {
    int bnum = 0;
    string shape = "";
    
    bool check[3] = {false, false, false};
    for(int i=y; i<y+3; i++)
        if(!board[x][i])
            check[i-y] = true;
    
    for(int i=x-1; i>=0; i--)
        for(int j=y; j<y+3; j++)
            if(check[j-y] && board[i][j])
                return false;
    
    for(int i=x; i<x+2; i++) {
        for(int j=y; j<y+3; j++) {
            if(!board[i][j])
                shape += "0";
            else {
                if(!bnum) bnum = board[i][j];
                if(board[i][j] != bnum)
                    return false;
            
                shape += "1";
            }
        }
    }
        
    if(!garo_map[shape])
        return false;
    
    return true;
}

bool check_sero(vector<vector<int>>& board, int x, int y) {
    int bnum = 0;
    string shape = "";
    
    bool check[2] = {false, false};
    for(int i=y; i<y+2; i++)
        if(!board[x][i])
            check[i-y] = true;
    
    for(int i=x-1; i>=0; i--)
        for(int j=y; j<y+2; j++)
            if(check[j-y] && board[i][j])
                return false;
    
    for(int i=x; i<x+3; i++) {
        for(int j=y; j<y+2; j++) {
            if(!board[i][j])
                shape += "0";
            else {
                if(!bnum) bnum = board[i][j];
                if(board[i][j] != bnum)
                    return false;
            
                shape += "1";
            }
        }
    }
    
    if(!sero_map[shape])
        return false;
    
    return true;
}

void pop_garo(vector<vector<int>>& board, int x, int y) {
    for(int i=x; i<x+2; i++)
        for(int j=y; j<y+3; j++)
            board[i][j] = 0;
    
    answer += 1;
}

void pop_sero(vector<vector<int>>& board, int x, int y) {
    for(int i=x; i<x+3; i++)
        for(int j=y; j<y+2; j++)
            board[i][j] = 0;
    
    answer += 1;
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    
    for(int i=0; i<3; i++) {
        garo_map[garo_block[i]] = 1;
        sero_map[sero_block[i]] = 1;
    }
    
    bool flag = true;
    while(flag) {
        flag = false;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // 가로
                if(i<n-1 && j<n-2) {
                    if(check_garo(board, i, j)) {
                        pop_garo(board, i, j);
                        flag = true;
                    }
                }
                // 세로
                if(i<n-2 && j<n-1) {
                    if(check_sero(board, i, j)) {
                        pop_sero(board, i, j);
                        flag = true;
                    }
                }
            }
        }
    }
    
    return answer;
}
