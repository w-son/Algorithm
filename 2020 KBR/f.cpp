// 외벽 점검 : 순열, 브루트 포스
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    
    sort(dist.begin(), dist.end());
    reverse(dist.begin(), dist.end());
    
    /*
     외벽 시작지점을 순차적으로 탐색
     원형인 구조의 시작에 n을 더함으로 간격을 유지하는 것이 포인트이다
    */
    for(int i=0; i<weak.size(); i++) {
        
        /*
         현재 원형 구조 기준으로
         사람을 1명부터 모두 뽑는 경우를 확인한다
        */
        int pick = 1;
        while(pick <= dist.size()) {
            
            vector<int> picked;
            for(int j=0; j<pick; j++)
                picked.push_back(dist[j]);
            
            // 뽑힌 사람을 모든 순열에 대해 확인한다
            do {
                
                int x = 0; // 현재 점검해야 하는 외벽 인덱스
                int y = 0; // 현재 점검에 나선 사람의 인덱스
                int start = weak[x];
                int end = start + picked[y];
            
                bool flag = false;
                while(1) {
                    // 현재 점검 외벽이 점검 구간에 포함되는 경우
                    if(start <= weak[x] && weak[x] <= end) {
                        // 다음 점검 지점으로 교체
                        x += 1;
                        if(x == weak.size()) {
                            flag = true;
                            break;
                        }
                    }
                    // 현재 점검 외벽이 점검 구간에 포함되지 않는 경우
                    else {
                        // 다음 사람으로 교체
                        y += 1;
                        if(y == picked.size()) {
                            break;
                        }
                        start = weak[x];
                        end = start + picked[y];
                    }
                }
            
                // 모든 지점이 커버되었다면 answer과 비교 후 갱신
                if(flag)
                    answer = pick < answer ? pick : answer;
                
            } while(prev_permutation(picked.begin(), picked.end()));
            
            pick += 1;
        }
        
        // 다음 원형 구조로 전환
        weak[0] += n;
        sort(weak.begin(), weak.end());
    }
    
    
    return answer == 9 ? -1 : answer;
}
