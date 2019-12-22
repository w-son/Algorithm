// 비밀지도 : 비트연산
#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++) {
        // 비트연산 |을 통해 지도의 i번째 열을 겹친다
        int temp = arr1[i] | arr2[i];
        string code = "";
        // 비트연산 &을 통해 지도의 #인 지점을 찾고 code에 저장한다
        for(int j=0; j<n; j++) {
            if(temp & (1<<j)) code = "#" + code;
            else code = ' ' + code;
        }
        answer.push_back(code);
    }
    
    return answer;
}
