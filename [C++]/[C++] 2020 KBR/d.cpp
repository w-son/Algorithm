// 가사 검색 : Trie 구조
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct trie {
    int count;
    bool flag;
    trie * next[26];
};

// 정방, 역방
// word의 길이에 따라 다른 Trie가 존재한다는 것을 유의해야 함
trie * O[10001];
trie * R[10001];

void insert(trie * iter, string s) {
    
    for(int i=0; i<s.size(); i++) {
        int a = s[i] - 'a';
        
        if(iter->next[a] == NULL)
            iter->next[a] = new trie({0, false, NULL});
        
        iter = iter->next[a];
        iter->count += 1;
    }
    
    iter->flag = true;
    return;
}

int query(trie * iter, string s) {
    
    for(int i=0; i<s.size(); i++) {
        char a = s[i];
        // ?가 나오는 지점에서 모든 next의 count를 더해 리턴
        if(a == '?') {
            int tmp = 0;
            for(int j=0; j<26; j++)
                if(iter->next[j] != NULL)
                    tmp += iter->next[j]->count;
            return tmp;
        }
        int b = a - 'a';
        if(iter->next[b] == NULL)
            return 0;
        else
            iter = iter->next[b];
    }
    return 0;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    
    for(int i=0; i<=10000; i++) {
        O[i] = new trie({0, false, NULL});
        R[i] = new trie({0, false, NULL});
    }
    
    // Trie 구조 생성
    for(int i=0; i<words.size(); i++) {
        string now = words[i];
        string rev = now;
        reverse(rev.begin(), rev.end());
        
        // 해당하는 word 길이의 Trie에 삽입
        int len = now.size();
        insert(O[len], now);
        insert(R[len], rev);
    }
    
    vector<int> answer;
    // Trie 구조에 질의
    for(int i=0; i<queries.size(); i++) {
        string now = queries[i];
        string rev = now;
        reverse(rev.begin(), rev.end());
        
        // 해당하는 word 길이의 Trie에 질의
        int len = now.size();
        int count_o = query(O[len], now);
        int count_r = query(R[len], rev);
        
        // ?가 앞에서부터 나오는 경우가 아니면 모두 정방향에서 처리 가능함
        if(now[0] == '?')
            answer.push_back(count_r);
        else
            answer.push_back(count_o);
    }
    
    return answer;
    
}
