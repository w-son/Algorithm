import java.util.*;

class Solution {

    public String[] solution(String s) {

        Stack<Character> stack = new Stack<>();

        int len = s.length();
        for(int i=0; i<len; i++) {
            char now = s.charAt(i);
            if(stack.empty()) {
                stack.push(now);
                continue;
            } else {
                char top = stack.peek();
                if((now == '0' && top == '1') || (now == '1' && top '0'))
                    stack.pop();
                else
                    stack.push(now);
            }
        }

        return stack.size();
    }
}