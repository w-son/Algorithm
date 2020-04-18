// 14425 문자열 집합 : 트라이 구조
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;

int answer = 0;

struct trie {
    bool end;
    trie * next[26];
};

void insert(trie * root, string s) {
    trie * iter = root;
    for(int i=0; i<s.size(); i++) {
        int now = s[i] - 'a';
        if(iter->next[now] == NULL)
            iter->next[now] = new trie({false, NULL});
        iter = iter->next[now];
    }
    iter->end = true;
    return;
}

void search(trie * root, string s) {
    trie * iter = root;
    for(int i=0; i<s.size(); i++) {
        int now = s[i] - 'a';
        if(iter->next[now] == NULL)
            return;
        iter = iter->next[now];
    }
    if(iter->end) answer += 1;
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    trie * root = new trie({false, NULL});
    
    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++) {
        string tmp; cin>>tmp;
        insert(root, tmp);
    }
    
    for(int i=0; i<m; i++) {
        string tmp; cin>>tmp;
        search(root, tmp);
    }
    
    cout<<answer<<'\n';
    
    return 0;
}

