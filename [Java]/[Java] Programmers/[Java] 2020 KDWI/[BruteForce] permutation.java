// 불량 사용자 : 순열 조합
import java.util.*;

class Solution {

    private int answer;
    private int users;
    private int bans;
    private String[] user_id;
    private String[] banned_id;
    private HashSet<String> set;

    // 초기화
    public void init(String[] user_id, String[] banned_id) {
        this.answer = 0;
        this.users = user_id.length;
        this.bans = banned_id.length;
        this.user_id = user_id;
        this.banned_id = banned_id;
        this.set = new HashSet<>();
    }

    boolean equals() {
        for(int i=0; i<bans; i++) {
            String user = user_id[i];
            String banned = banned_id[i];
            if(user.length() != banned.length()) return false;
            for(int j=0; j<user.length(); j++)
                if(banned.charAt(j)!='*' && banned.charAt(j)!=user.charAt(j))
                    return false;
        }
        return true;
    }

    // 배열 원소 바꾸는 함수
    public void swap(int ia, int ib) {
        String temp = user_id[ia];
        user_id[ia] = user_id[ib];
        user_id[ib] = temp;
    }

    // 순열 구현부
    public void Pmt(int idx) {
        if(idx == users) {
            String[] arr = new String[bans];
            for(int i=0; i<bans; i++) arr[i] = user_id[i];
            Arrays.sort(arr);
            String temp = "";
            for(int i=0; i<bans; i++) temp += arr[i];
            if(equals() && set.add(temp))
                this.answer += 1;

            return;
        }
        for(int i=idx; i<users; i++) {
            swap(idx, i);
            Pmt(idx + 1);
            swap(idx, i);
        }
    }

    public int solution(String[] user_id, String[] banned_id) {
        init(user_id, banned_id);
        Pmt(0);
        return answer;
    }

}