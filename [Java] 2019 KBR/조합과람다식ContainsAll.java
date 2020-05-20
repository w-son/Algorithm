// 후보키 : 순열조합, 람다식, containsAll
import java.util.*;

class Solution {

    private int answer;
    private HashSet<ArrayList<Integer>> set;
    private String[][] relation;
    private int row;
    private int col;
    private int[] arr;

    public void init(String[][] relation) {
        this.answer = 0;
        this.set = new HashSet<>();
        this.relation = relation;
        this.row = relation.length;
        this.col = relation[0].length;
        this.arr = new int[this.col];
        for(int i=0; i<this.col; i++)
            arr[i] = i;
    }

    public boolean isCandidate(int n) {

        for(int i=0; i<this.row; i++) {
            for(int j=i+1; j<this.row; j++) {
                boolean flag = true;
                for(int k=0; k<n; k++) {
                    int key = arr[k];
                    if(!relation[i][key].equals(relation[j][key]))
                        flag = false;
                }
                if(flag) return false;
            }
        }

        ArrayList<Integer> temp = new ArrayList<>();
        for(int i=0; i<n; i++)
            temp.add(arr[i]);

        // Collections.sort(temp, (a, b) -> { return a-b; });
        for(ArrayList<Integer> key : set)
            if(temp.containsAll(key))
                return false;

        this.answer += 1;
        set.add(temp);
        return true;
    }

    // 순열 조합
    public void swap(int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
    public void pmt(int idx, int n) {
        if(idx == this.col) {
            isCandidate(n);
        }
        for(int i=idx; i<this.col; i++) {
            swap(idx, i);
            pmt(idx+1, n);
            swap(idx, i);
        }
    }

    public int solution(String[][] relation) {

        init(relation);
        for(int i=1; i<=this.col; i++)
            pmt(0, i);

        return answer;
    }
}