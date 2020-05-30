import java.io.*;
import java.util.*;

public class Main {

    public static int t;
    public static int n;
    public static int d;
    public static int c;
    public static int a;
    public static int b;
    public static int s;
    public static int[] dist;
    public static boolean[] check;
    public static Queue<int[]> pq;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());

        for(int i=0; i<t; i++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            dist = new int[n+1];
            for(int j=1; j<=n ;j++) dist[j] = -1;
            check = new boolean[n+1];
            pq = new PriorityQueue<>(new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return o1[1] < o2[1] ? -1 : 1;
                }
            });

            Map<Integer, List<int[]>> map = new HashMap<>();
            for(int j=1; j<=n; j++)
                map.put(j, new ArrayList<>());

            for(int j=0; j<d; j++) {
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                s = Integer.parseInt(st.nextToken());

                List<int[]> temp = map.get(b);
                int[] edge = {a, s};
                temp.add(edge);
                map.put(b, temp);
            }

            dist[c] = 0;
            check[c] = true;
            List<int[]> start = map.get(c);
            for(int[] item : start) {
                int[] add = {item[0], dist[c] + item[1]};
                pq.offer(add);
            }
            while(!pq.isEmpty()) {
                int[] now = pq.poll();
                if(check[now[0]]) continue;
                dist[now[0]] = now[1];
                check[now[0]] = true;
                List<int[]> next = map.get(now[0]);
                for(int[] item : next) {
                    if(!check[item[0]]) {
                        int[] add = {item[0], dist[now[0]] + item[1]};
                        pq.offer(add);
                    }
                }
            }

            int cnt = 0;
            int time = -1;
            for(int j=1; j<=n; j++) {
                if(dist[j] != -1) cnt += 1;
                if(dist[j] > time) time = dist[j];
            }

            System.out.println("" + cnt + " " + time);

        }

    }

}