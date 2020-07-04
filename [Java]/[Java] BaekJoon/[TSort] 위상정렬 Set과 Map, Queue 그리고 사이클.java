import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.List;

public class Main {

    public static class Node {
        int idx;
        Set<Integer> from;
        Set<Integer> to;

        public Node(int idx) {
            this.idx = idx;
            this.from = new HashSet<>();
            this.to = new HashSet<>();
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Map<Integer, Node> map = new HashMap<>();
        for(int i=0; i<m; i++) {
            String[] arr1 = br.readLine().split(" ");
            int[] arr2 = Arrays.stream(arr1).map(Integer::parseInt).mapToInt(Integer::intValue).toArray();
            for(int j=1; j<arr2.length-1; j++) {
                Node child = map.getOrDefault(arr2[j], new Node(arr2[j]));
                Node parent = map.getOrDefault(arr2[j+1], new Node(arr2[j+1]));

                child.to.add(arr2[j+1]);
                parent.from.add(arr2[j]);

                map.put(arr2[j], child);
                map.put(arr2[j+1], parent);
            }
        }

        Queue<Node> queue = new LinkedList<>();
        for(Integer key : map.keySet()) {
            if(map.get(key).from.isEmpty())
                queue.add(map.get(key));
        }

        List<Integer> list = new ArrayList<>();
        // 담당 PD 가 없는 애들을 넣어준다
        for(int i=1; i<=n; i++)
            if(map.getOrDefault(i, null) == null)
                list.add(i);

        while(!queue.isEmpty()) {
            Node now = queue.poll();
            list.add(now.idx);

            for(Integer key : now.to) {
                Node next = map.get(key);
                next.from.remove(now.idx);
                if(next.from.isEmpty())
                    queue.add(next);
            }
        }

        if(list.size() == n) {
            for(Integer music : list)
                System.out.println(music);
        } else { // 사이클을 형성하는 경우
            System.out.println(0);
        }
    }
}
