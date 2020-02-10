// 자물쇠와 열쇠 : 구현
#include <string>
#include <vector>
using namespace std;

int extended[60][60];

// extended의 -1을 지우는 함수
void clear() {
    for(int i=0; i<60; i++)
        for(int j=0; j<60; j++)
            if(extended[i][j] == -1)
                extended[i][j] = 0;
}

// 주어진 key를 시계 방향으로 90도 회전시키는 함수
void spin(int n, vector<vector<int>>& key) {
    vector<vector<int>> result = key;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            key[i][j] = result[j][n-i-1];
    return;
}

// 주어진 key를 lock에 맞춰보는 함수
bool unlock(int n, int nx, int ny, vector<vector<int>>& key) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            if(key[i][j] == 1 && extended[i+nx][j+ny] == 1) {
                clear();
                return false;
            }
            else if(key[i][j] == 1 && extended[i+nx][j+ny] == 0)
                extended[i+nx][j+ny] = -1;
        }
    return true;
}

// key가 lock을 풀 수 있는지 확인하는 함수
bool check(int n, int m) {
    bool ret = true;
    for(int i=n-1; i<n+m-1; i++)
        for(int j=n-1; j<n+m-1; j++) {
            if(extended[i][j] == 0)
                ret = false;
        }
    clear();
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = key.size();
    int m = lock.size();
    // extended 2차원 배열로 옮기는 과정
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            extended[i+n-1][j+n-1] = lock[i][j];
    
    for(int i=0; i<n+m-1; i++)
        for(int j=0; j<n+m-1; j++)
            for(int k=0; k<4; k++) {
                if(unlock(n, i, j, key))
                    if(check(n, m))
                        return true;
                spin(n, key);
            }
    
    return false;
}
