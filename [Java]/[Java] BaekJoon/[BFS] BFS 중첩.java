import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static int n;
    private static int m;
    private static int[][] map;
    private static int[] mx = new int[] { 1, -1, 0, 0 };
    private static int[] my = new int[] { 0, 0, 1, -1 };

    public static boolean genQueue(Queue<Point> queue) {
        boolean check = false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] == 0)
                    queue.add(new Point(i, j));
                else
                    check = true;
            }
        }
        // true 일 경우 아직 남아 있는 빙산 있음
        return check;
    }

    public static boolean melt(Queue<Point> queue) {

        while(!queue.isEmpty()) {
            Point now = queue.poll();

            for(int i=0; i<4; i++) {
                int X = now.x + mx[i];
                int Y = now.y + my[i];
                if(0<=X&&X<n && 0<=Y&&Y<m && map[X][Y]>0)
                    map[X][Y] -= 1;
            }
        }

        // 두 덩어리 이상으로 나뉘어졌는지 확인한다
        int cnt = 0;
        boolean[][] check = new boolean[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] > 0 && !check[i][j]) {
                    Queue<Point> q = new LinkedList<Point>();
                    q.add(new Point(i, j));
                    check[i][j] = true;

                    while(!q.isEmpty()) {
                        Point now = q.poll();

                        for(int k=0; k<4; k++) {
                            int X = now.x + mx[k];
                            int Y = now.y + my[k];
                            if(0<=X&&X<n && 0<=Y&&Y<m && map[X][Y]>0 && !check[X][Y]) {
                                q.add(new Point(X, Y));
                                check[X][Y] = true;
                            }
                        }
                    }
                    cnt += 1;
                }
            }
        }

        return cnt > 1;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];

        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        int answer = 0;
        while(true) {
            Queue<Point> queue = new LinkedList<Point>();
            boolean check = genQueue(queue); // 정상적으로 Point가 담겨진다

            if(check) { // 빙산이 있다면 녹인다
                answer += 1;
                boolean isDivided = melt(queue);

                // 두개 이상으로 나뉘었다면 탈출한다
                if(isDivided) break;
            } else {
                answer = 0;
                break;
            }
        }

        System.out.println(answer);
    }

}