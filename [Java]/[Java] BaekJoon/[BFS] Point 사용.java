import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static int[] check;

    public static void main(String[] args) throws Exception {

        StringBuilder answer = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int F = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int G = Integer.parseInt(st.nextToken());
        int U = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        check = new int[F + 1];
        Queue<Point> queue = new LinkedList<Point>();
        queue.add(new Point(S, 0));
        check[S] = 1;

        while(!queue.isEmpty()) {
            Point now = queue.poll();

            if(now.x == G) {
                System.out.println(now.y);
                return;
            }

            int up = now.x + U;
            int down = now.x - D;

            if(up <= F && check[up] == 0) {
                check[up] = 1;
                queue.add(new Point(up, now.y + 1));
            }
            if(down > 0 && check[down] == 0) {
                check[down] = 1;
                queue.add(new Point(down, now.y + 1));
            }
        }

        System.out.println("use the stairs");
    }

}