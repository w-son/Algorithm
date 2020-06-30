import java.io.*;
import java.util.*;

public class Main {

    public static int n;
    public static int m;
    public static int[][] map;
    public static int[][][] check;
    public static int[] mx = {1, -1, 0, 0};
    public static int[] my = {0, 0, 1, -1};

    public static class Node {
        int x;
        int y;
        int cnt;
        int wall;

        public Node(int x, int y, int cnt, int wall) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.wall = wall;
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        check = new int[n][m][2];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = str.charAt(j) - '0';
            }
        }

        Queue<Node> queue = new LinkedList<>();
        Node start = new Node(0, 0, 1, 0);
        check[0][0][0] = check[0][0][1] = 1;
        queue.add(start);

        while (!queue.isEmpty()) {
            Node now = queue.poll();

            for (int i = 0; i < 4; i++) {
                int X = now.x + mx[i];
                int Y = now.y + my[i];
                if (0 <= X && X < n && 0 <= Y && Y < m) {

                    if (map[X][Y] == 0) {
                        Node next = new Node(X, Y, now.cnt + 1, now.wall);
                        if(check[X][Y][now.wall] == 0 || next.cnt < check[X][Y][now.wall]) {
                            check[X][Y][now.wall] = next.cnt;
                            queue.add(next);
                        }
                    }

                    else if (map[X][Y] == 1 && now.wall == 0) {
                        Node next = new Node(X, Y, now.cnt + 1, 1);
                        if(check[X][Y][1] == 0 || next.cnt < check[X][Y][1]) {
                            check[X][Y][1] = next.cnt;
                            queue.add(next);
                        }
                    }

                }
            }
        }

        int answer;
        int a = check[n - 1][m - 1][0];
        int b = check[n - 1][m - 1][1];
        if (a == 0 && b == 0) answer = -1;
        else if (a == 0 && b != 0) answer = b;
        else if (a != 0 && b == 0) answer = a;
        else answer = Math.min(a, b);
        System.out.println(answer);
    }

}

