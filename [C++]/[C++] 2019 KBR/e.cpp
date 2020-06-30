// 매칭 점수 : cctype, find 함수
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cctype>
using namespace std;

bool cmp(pair<int, double>& a, pair<int, double>& b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

// 소문자로 바꿔주는 함수
void convert(string& target) {
    for(int i=0; i<target.size(); i++)
        if(isalpha(target[i]))
            target[i] = tolower(target[i]);
    return;
}

// 기본점수를 구하는 함수
int primaryScore(string word, string page) {
    int count = 0;
    string temp = "";
    for(int i=0; i< page.size(); i++) {
        if(isalpha(page[i]))
            temp += page[i];
        else {
            if(temp == word)
                count += 1;
            temp = "";
        }
    }
    return count;
}

// url을 찾아주는 함수
string findUrl(string page) {
    string target = "<meta property=\"og:url\" content=\"https://";
    int idx = page.find(target);
    idx += target.size();
    string url = "";
    while(page[idx] != '\"')
        url += page[idx++];
    
    return url;
}

// external url을 구해주는 함수
vector<string> findExternalUrls(string page) {
    string target = "<a href=\"https://";
    vector<string> urls;
    int base = 0;
    int start;
    while((start = page.find(target, base)) != string::npos) {
        start += target.size();
        string url = "";
        while(page[start] != '\"')
            url += page[start++];
        base = start;
        urls.push_back(url);
    }
    return urls;
}

int solution(string word, vector<string> pages) {
    // 소문자로 전환
    convert(word);
    for(int i=0; i<pages.size(); i++)
        convert(pages[i]);
    
    // 페이지들의 이름을 저장할 vector
    vector<string> urls;
    for(int i=0; i<pages.size(); i++)
        urls.push_back(findUrl(pages[i]));
    
    // 페이지들의 외부링크를 저장할 vector
    vector<vector<string>> links;
    for(int i=0; i<pages.size(); i++)
        links.push_back(findExternalUrls(pages[i]));
    
    // 페이지들의 기본점수를 저장할 vector
    vector<int> pScores;
    for(int i=0; i<pages.size(); i++)
        pScores.push_back(primaryScore(word, pages[i]));
    
    // 페이지들의 링크점수를 저장할 hash map
    unordered_map<string, double> lScores;
    for(int i=0; i<pages.size(); i++) {
        double linkScore = (double) pScores[i] / links[i].size();
        for(int j=0; j<links[i].size(); j++)
            lScores[links[i][j]] += linkScore;
    }
    
    // 매칭점수와 index를 저장할 vector
    vector<pair<int, double>> mScores;
    for(int i=0; i<pages.size(); i++) {
        string now = urls[i];
        double matchScore = (double) pScores[i] + lScores[now];
        mScores.push_back(make_pair(i, matchScore));
    }
    
    sort(mScores.begin(), mScores.end(), cmp);
    
    return mScores[0].first;
}
