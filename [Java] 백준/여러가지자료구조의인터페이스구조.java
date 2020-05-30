import java.io.*;
import java.util.*;

public class Main {

    public static int n;
    public static int m;
    public static Map<Integer, List<Integer>> map;
    public static Set<Integer> set;
    public static Queue<Node> queue;

    public static class Node {
        int now;
        int cnt;
        public Node(int now, int cnt) {
            this.now = now;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        map = new HashMap<>();
        set = new HashSet<>();
        queue = new LinkedList<>();
        st = new StringTokenizer(br.readLine());
        int from = Integer.parseInt(st.nextToken());
        int to = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            List<Integer> la = map.getOrDefault(a, new ArrayList<>());
            List<Integer> lb = map.getOrDefault(b, new ArrayList<>());
            la.add(b); lb.add(a);
            map.put(a, la); map.put(b, lb);
        }

        Node start = new Node(from, 0);
        set.add(from);
        queue.add(start);

        int answer = -1;
        while(!queue.isEmpty()) {
            Node now = queue.poll();
            if(now.now == to) {
                answer = now.cnt;
                break;
            }
            List<Integer> list = map.getOrDefault(now.now, new ArrayList<>());
            for(Integer next : list) {
                if(set.add(next)) queue.add(new Node(next, now.cnt+1));
            }
        }
        System.out.println(answer);
    }

}