// 후보키 : 순열과 조합
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int cols = relation[0].size();
    string var[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    unordered_map<string, int> table;
    
    for(int i=1; i<=cols; i++) {
        vector<int> combs;
        for(int j=0; j<i; j++) combs.push_back(1);
        for(int j=0; j<cols-i; j++) combs.push_back(0);
        // i개의 칼럼을 뽑는 경우의 수를 따져주기 위해 순열 사용
        do {
            unordered_map<string, int> m;
            bool flag = true;
            for(int x=0; x<relation.size(); x++) {
                string temp = "";
                for(int y=0; y<cols; y++)
                    if(combs[y]) temp += relation[x][y];
                if(!m[temp]) m[temp] = 1;
                else {
                    flag = false;
                    break;
                }
            }
            // 현재 칼럼 조합이 유일한 경우
            if(flag) {
                // 현재 칼럼 조합이 채택된 임의의 후보키를 포함하지 않는 경우 true
                bool f1 = true;
                for(auto x=table.begin(); x!=table.end(); x++) {
                    string candidate = x->first;
                    // 현재 칼럼 조합이 채택된 현재 후보키를 포함하지 않는 경우 true
                    bool f2 = false;
                    for(int y=0; y<candidate.size(); y++)
                        if(!combs[candidate[y]-'0'])
                            f2 = true;
                    if(!f2) f1 = false;
                }
                // 현재 칼럼 조합을 후보키로 채택
                if(f1) {
                    string accept = "";
                    for(int x=0; x<cols; x++)
                        if(combs[x]) accept += var[x];
                    table[accept] = 1;
                    answer += 1;
                }
            }
            
        } while(prev_permutation(combs.begin(), combs.end()));
    }
    return answer;
}
