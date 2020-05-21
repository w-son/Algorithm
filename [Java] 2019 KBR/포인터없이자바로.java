// 길 찾기 게임 : 포인터 사용하던 문제
import java.util.*;

class Node {
    int num;
    int x;
    int y;
    Node left;
    Node right;
    public Node(int num, int x, int y) {
        this.num = num;
        this.x = x;
        this.y = y;
    }
}

class Solution {

    private int[][] answer;
    private int preidx;
    private int postidx;
    private HashSet<Integer> set;
    private HashMap<Integer, ArrayList<Node>> map;
    private ArrayList<Integer> list;

    // 전위 순회
    public void preorder(Node now) {
        this.answer[0][this.preidx++] = now.num;
        if(now.left != null) preorder(now.left);
        if(now.right != null) preorder(now.right);
    }

    // 후위 순회
    public void postorder(Node now) {
        if(now.left != null) postorder(now.left);
        if(now.right != null) postorder(now.right);
        this.answer[1][this.postidx++] = now.num;
    }

    // 트리 생성 메서드
    public void maketree(Node node, int left, int right, int idx) {
        if(idx < list.size()) {
            int now = node.x;
            ArrayList<Node> nodes = map.get(list.get(idx));
            for(Node n : nodes) {
                if(left <= n.x && n.x <= now) {
                    node.left = n;
                    maketree(n, left, now, idx+1);
                }
                if(now <= n.x && n.x <= right) {
                    node.right = n;
                    maketree(n, now, right, idx+1);
                }
            }
        }
    }

    public int[][] solution(int[][] nodeinfo) {

        // 초기화
        answer = new int[2][nodeinfo.length];
        preidx = postidx = 0;
        set = new HashSet<>();
        map = new HashMap<>();
        list = new ArrayList<>();

        // 각 높이에 해당하는 노드를 분류
        for(int i=0; i<nodeinfo.length; i++) {
            int x = nodeinfo[i][0];
            int y = nodeinfo[i][1];
            Node node = new Node(i+1, x, y);
            set.add(y);
            ArrayList<Node> temp = map.getOrDefault(y, new ArrayList<Node>());
            temp.add(node);
            map.put(y, temp);
        }

        for(Integer key : set) list.add(key);
        Collections.sort(list, (o1, o2) -> { return o2 - o1; });

        Node root = map.get(list.get(0)).get(0);
        maketree(root, 0, 100000, 1);
        preorder(root);
        postorder(root);

        return this.answer;
    }
}