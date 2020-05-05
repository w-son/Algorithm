// 모의고사 : 리스트
import java.util.*;

class Solution {

    private int max;

    public int count(int[] answers, int[] arr) {
        int score = 0;
        for(int i=0; i<answers.length; i++) {
            int guess = arr[i % arr.length];
            if(guess == answers[i])
                score += 1;
        }
        if(score > max)
            max = score;
        return score;
    }

    public int[] solution(int[] answers) {

        int[] a = {1, 2, 3, 4, 5};
        int[] b = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

        max = 0;
        int[] score = new int[3];
        score[0] = count(answers, a);
        score[1] = count(answers, b);
        score[2] = count(answers, c);

        int idx = 0;
        for(int i=0; i<3; i++)
            if(score[i] == max)
                idx += 1;

        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<3; i++)
            if(score[i] == max)
                list.add(i + 1);

        return list.stream().mapToInt(i->i.intValue()).toArray();
    }

}