// 자동완성 : Trie 구조
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) { return a.size() < b.size(); }

struct trie {
    int count;
    bool flag;
    trie * next[26];
};

int solution(vector<string> words) {
    int answer = 0;
    sort(words.begin(), words.end());
    // 초기화 방식 유의
    trie root = {0, false, NULL};
    
    for(int i=0; i<words.size(); i++) {
        string now = words[i];
        trie * iter = &root;
        for(int j=0; j<now.size(); j++) {
            int alpha = now[j] -'a';
            if(iter->next[alpha] == NULL) {
                iter->next[alpha] = new trie({0, false, NULL});
                iter = iter->next[alpha];
                iter->count = 1;
            }
            else {
                iter = iter->next[alpha];
                if(iter->count == 1) answer += 1;
                iter->count += 1;
                answer += 1;
                if(iter->flag) {
                    answer -= 1;
                    iter->flag = false;
                }
            }
        }
        iter->flag = true;
    }
    
    return answer + words.size();
}
