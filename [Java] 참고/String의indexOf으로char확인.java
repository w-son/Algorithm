import java.util.*;

class Solution {

    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        int len = skill_trees.length;

        for(int i=0; i<len; i++) {
            int idx = 0;

            boolean flag = true;
            for(int j=0; j<skill_trees[i].length(); j++) {
                char now = skill_trees[i].charAt(j);
                if(skill.indexOf(now) != -1 && now != skill.charAt(idx++)) {
                    flag = false;
                    break;
                }
            }
            if(flag) answer += 1;
        }

        return answer;
    }
}